#include <openssl/evp.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read.h"
#include "../include/hash.h"

void hash_passwords(password *passwords, int passwords_count)
{   
    initialize_passwords(passwords, passwords_count);

    for (int i = 0; i < passwords_count; i++)
    {
        // create a new message digest context
        EVP_MD_CTX *message_digest = EVP_MD_CTX_new();

        // initialize the message digest context with the SHA256 algorithm
        EVP_DigestInit_ex(message_digest, EVP_sha256(), NULL);
        
        // hash the weak password
        EVP_DigestUpdate(message_digest, passwords[i].weak_password, strlen(passwords[i].weak_password));
        
        // finalize the message digest
        unsigned char hash[SHA256_DIGEST_LENGTH];
        EVP_DigestFinal_ex(message_digest, hash, NULL);

        // free the message digest context
        EVP_MD_CTX_free(message_digest);

        // convert the hash to hexadecimal
        to_hex(hash, passwords[i].password_hash);
    }
}

void initialize_passwords(password *passwords, int passwords_count)
{
    for (int i = 0; i < passwords_count; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            passwords[i].password_hash[j] = 0;
        }
    }
}

void to_hex(unsigned char *hash, char *password_hash)
{
    for (int i = 0, j = 0; i < SHA256_DIGEST_LENGTH; i++, j += 2)
    {
        // getting number stored at hash
        int decimal = hash[i];

        // converting number to hexadecimal
        int first_digit = decimal / 16;
        int second_digit = decimal % 16;

        // converting number to string 
        password_hash[j] = (first_digit < 10) ? (first_digit + '0') : (first_digit - 10 + 'a');
        password_hash[j + 1] = (second_digit < 10) ? (second_digit + '0') : (second_digit - 10 + 'a');
    }

    // putting NULL terminator at end of string
    password_hash[2 * SHA256_DIGEST_LENGTH] = '\0';    
}