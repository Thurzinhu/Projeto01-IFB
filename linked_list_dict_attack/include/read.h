#ifndef READ_H
#define READ_H

#define MAX 70

typedef struct 
{
    char name[MAX];                
    char birth_date[MAX];           
    char username[MAX];            
    char password_hash[MAX];        // Hash da senha
    char last_password_change[MAX]; // data da última mudança de senha
}
user;

typedef struct 
{
    char weak_password[MAX];
    char password_hash[MAX];
}
password;

typedef struct user_node
{
    user current_user;
    struct user_node *next;
}
user_node;

typedef struct password_node
{
    password current_password;
    struct password_node *next;
}
password_node;

user_node *read_users_data(FILE *users_data);
password_node *read_weak_passwords(FILE *weak_passwords);

#endif