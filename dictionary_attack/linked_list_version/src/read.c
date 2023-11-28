#include <stdio.h>
#include <stdlib.h>
#include "../include/read.h"

user_node *read_users_data(FILE *users_data)
{
    char buffer;
    user_node *root = NULL;
    while (fscanf(users_data, " %c", &buffer) == 1)
    {
        ungetc(buffer, users_data);

        user_node *new_node = malloc(sizeof(user_node));
        new_node->next = root;
        root = new_node;

        fscanf(users_data, " %[^\n]s", new_node->current_user.name);
        fscanf(users_data, " %[^\n]s", new_node->current_user.birth_date);
        fscanf(users_data, " %[^\n]s", new_node->current_user.username);
        fscanf(users_data, " %[^\n]s", new_node->current_user.password_hash);
        fscanf(users_data, " %[^\n]s", new_node->current_user.last_password_change);

        char separator[4];
        fscanf(users_data, " %[^\n]s", separator);
    }

    return root;
}

password_node *read_weak_passwords(FILE *weak_passwords)
{
    char buffer;
    password_node *root = NULL;
    while (fscanf(weak_passwords, " %c", &buffer) == 1)
    {
        ungetc(buffer, weak_passwords);

        password_node *new_node = malloc(sizeof(password_node));
        new_node->next = root;
        root = new_node;

        fscanf(weak_passwords, " %[^\n]s", new_node->current_password.weak_password);
    }

    return root;
}