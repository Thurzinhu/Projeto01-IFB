#ifndef HASH_H
#define HASH_H

void initialize_passwords(password *passwords, int passwords_count);
void hash_passwords(password *passwords, int password_count);
void to_hex(unsigned char *hash, char *password_hash);

#endif