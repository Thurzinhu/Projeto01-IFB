#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"

void validate_arguments(int argc, char *argv[], FILE **users_data, FILE **weak_passwords, FILE **report)
{
    if (argc != 4)
    {
        printf("Usage: %s <users_data> <weak_passwords> <report>\n", argv[0]);
    }

    *users_data = fopen(argv[1], "r");
    if (*users_data == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        exit(1);
    }

    *weak_passwords = fopen(argv[2], "r");
    if (*weak_passwords == NULL)
    {
        printf("Could not open file %s\n", argv[2]);
        exit(1);
    }

    *report = fopen(argv[3], "w");
    if (*report == NULL)
    {
        printf("Could not open file %s\n", argv[3]);
        exit(1);
    }
}