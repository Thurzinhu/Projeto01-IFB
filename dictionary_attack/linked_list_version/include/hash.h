#ifndef HASH_H
#define HASH_H

void hash_passwords(password_node *passwords);
void initialize_passwords(password_node *passwords);
void to_hex(unsigned char *hash, char *password_hash);

#endif