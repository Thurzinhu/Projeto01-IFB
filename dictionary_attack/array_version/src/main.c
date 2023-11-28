#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"
#include "../include/read.h"
#include "../include/hash.h"
#include "../include/report.h"

int main(int argc, char *argv[])
{
    FILE *users_data, *weak_passwords, *report; 
    validate_arguments(argc, argv, &users_data, &weak_passwords, &report);
    
    user *users = NULL;
    int users_count = 0;
    read_users_data(users_data, &users, &users_count);

    password *passwords = NULL;
    int passwords_count = 0;
    read_weak_passwords(weak_passwords, &passwords, &passwords_count);

    hash_passwords(passwords, passwords_count);
    generate_report(report, users, passwords, users_count, passwords_count);

    // freeing memory
    free(users);
    free(passwords);

    // closing files
    fclose(users_data);
    fclose(weak_passwords);
    fclose(report);
}