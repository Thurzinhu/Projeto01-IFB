#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read.h"
#include "../include/report.h"

void generate_report(FILE *report, user_node *users, password_node *passwords)
{
    // starting from the root and going through all the users
    for (user_node *user_tmp = users; user_tmp != NULL; user_tmp = user_tmp->next)
    {
        // starting from the root and going through all the passwords
        for (password_node *password_tmp = passwords; password_tmp != NULL; password_tmp = password_tmp->next)
        {
            // if the password hash matches the user password hash user password is weak
            if (strcmp(user_tmp->current_user.password_hash, password_tmp->current_password.password_hash) == 0)
            {
                fprintf(report, "%s\n", user_tmp->current_user.username);
                fprintf(report, "%s\n", password_tmp->current_password.weak_password);
                fprintf(report, "%s\n", user_tmp->current_user.name);
                fprintf(report, "%s\n", user_tmp->current_user.birth_date);
                fprintf(report, "---\n");
            }
        }
    }
}