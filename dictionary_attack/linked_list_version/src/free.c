#include <stdio.h>
#include <stdlib.h>
#include "../include/read.h"
#include "../include/free.h"

void free_users(user_node *users)
{
    user_node *tmp = users;
    while (tmp != NULL)
    {
        user_node *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

void free_passwords(password_node *passwords)
{
    password_node *tmp = passwords;
    while (tmp != NULL)
    {
        password_node *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}