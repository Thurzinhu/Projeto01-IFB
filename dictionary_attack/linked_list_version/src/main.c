#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"
#include "../include/read.h"
#include "../include/hash.h"
#include "../include/report.h"
#include "../include/free.h"

int main(int argc, char *argv[])
{
    // validating arguments
    FILE *users_data, *weak_passwords, *report;
    validate_arguments(argc, argv, &users_data, &weak_passwords, &report);

    // reading data
    user_node *users = read_users_data(users_data);
    password_node *passwords = read_weak_passwords(weak_passwords);

    // hashing passwords
    hash_passwords(passwords);

    // printing report
    generate_report(report, users, passwords);
    
    // freeing memory
    free_users(users);
    free_passwords(passwords);

    // closing files
    fclose(users_data);
    fclose(weak_passwords);
    fclose(report);
}