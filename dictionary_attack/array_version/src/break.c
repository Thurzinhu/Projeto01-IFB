#include <stdio.h>
#include <string.h>
#include "../include/read.h"
#include "../include/break.h"

int is_broken(char *password_hash, char *encrypted_week_password)
{
    return strcmp(password_hash, encrypted_week_password) == 0;
}