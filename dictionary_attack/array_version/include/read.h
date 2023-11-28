#ifndef READ_H
#define READ_H

#define MAX 70

typedef struct 
{
    char name[MAX];                
    char birth_date[MAX];           
    char username[MAX];       
    char password_hash[MAX];
    char last_password_change[MAX];
}
user;

typedef struct 
{
    char weak_password[MAX];
    char password_hash[MAX];
}
password;

void read_users_data(FILE *users_data, user **users, int *users_count);
void read_weak_passwords(FILE *weak_passwords, password **passwords, int *passwords_count);

#endif