#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read.h"

void read_users_data(FILE *users_data, user **users, int *users_count)
{
    char buffer[MAX];
    while (fscanf(users_data, " %[^\n]s", buffer) == 1)
    {
        // updating users count when reading a separator
        if (strcmp(buffer, "---") == 0)
            (*users_count)++;
    }

    // reset file pointer to the beginning of the file
    fseek(users_data, 0, SEEK_SET);

    *users = malloc(sizeof(user) * (*users_count));
    for (int i = 0; i < *users_count; i++)
    {
        fscanf(users_data, " %[^\n]s", (*users)[i].name);
        fscanf(users_data, " %[^\n]s", (*users)[i].birth_date);
        fscanf(users_data, " %[^\n]s", (*users)[i].username);
        fscanf(users_data, " %[^\n]s", (*users)[i].password_hash);
        fscanf(users_data, " %[^\n]s", (*users)[i].last_password_change);

        // reading separator
        fscanf(users_data, " %[^\n]s", buffer);
    }
}

void read_weak_passwords(FILE *weak_passwords, password **passwords, int *passwords_count)
{
    char buffer[MAX];
    while (fscanf(weak_passwords, " %[^\n]s", buffer) == 1)
    {
        (*passwords_count)++;
    }

    // reset file pointer to the beginning of the file
    fseek(weak_passwords, 0, SEEK_SET);

    *passwords = malloc(sizeof(password) * (*passwords_count));
    for (int i = 0; i < *passwords_count; i++)
    {
        fscanf(weak_passwords, " %[^\n]s", (*passwords)[i].weak_password);
    }
}