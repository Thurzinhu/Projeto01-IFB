#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read.h"
#include "../include/report.h"
#include "../include/break.h"

void generate_report(FILE *report, user *users, password *passwords, int users_count, int passwords_count)
{
    for (int i = 0; i < users_count; i++)
    {
        for (int j = 0; j < passwords_count; j++)
        {
            // if the password hash matches the user password hash
            // user password is weak
            if (is_broken(users[i].password_hash, passwords[j].password_hash))
            {
                fprintf(report, "%s\n", users[i].username);
                fprintf(report, "%s\n", passwords[j].weak_password);
                fprintf(report, "%s\n", users[i].name);
                fprintf(report, "%s\n", users[i].birth_date);
                fprintf(report, "---");
                
                if (i + 1 != users_count)
                    fprintf(report, "\n");
            }
        }
    }
}