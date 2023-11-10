#include <openssl/evp.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read.h"
#include "../include/hash.h"

void hash_passwords(password_node *passwords)
{   
    initialize_passwords(passwords);

    password_node *tmp = passwords;
    while (tmp != NULL)
    {
        // create a new message digest context
        EVP_MD_CTX *message_digest = EVP_MD_CTX_new();

        // initialize the message digest context with the SHA256 algorithm
        EVP_DigestInit_ex(message_digest, EVP_sha256(), NULL);
        
        // hash the weak password
        EVP_DigestUpdate(message_digest, tmp->current_password.weak_password, strlen(tmp->current_password.weak_password));
        
        // finalize the message digest
        unsigned char hash[SHA256_DIGEST_LENGTH];
        EVP_DigestFinal_ex(message_digest, hash, NULL);

        // free the message digest context
        EVP_MD_CTX_free(message_digest);

        // convert the hash to hexadecimal
        to_hex(hash, tmp->current_password.password_hash);

        tmp = tmp->next;
    }
}

void initialize_passwords(password_node *passwords)
{
    password_node *tmp = passwords;
    while (tmp != NULL)
    {
        for (int i = 0; i < MAX; i++)
        {
            tmp->current_password.password_hash[i] = '\0';
        }

        tmp = tmp->next;
    }
}

void to_hex(unsigned char *hash, char *password_hash)
{
    for (int i = 0, j = 0; i < SHA256_DIGEST_LENGTH; i++, j += 2)
    {
        int decimal = hash[i];

        password_hash[j] = decimal / 16;
        password_hash[j + 1] = decimal % 16;

        for (int k = j; k <= j + 1; k++)
        {
            if (password_hash[k] < 10)
            {
                password_hash[k] += '0';
            }
            else
            {
                password_hash[k] += 'a' - 10;
            }
        }
    }
}