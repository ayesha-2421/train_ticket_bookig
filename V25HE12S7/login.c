#include <stdio.h>
#include "login.h"
#include<string.h>
#include"admin.h"
void menu2();

int check_username(char username[])
{
    char existing_username[50];
    char existing_password[100];

    FILE *fp;

    fp = fopen("usr_logins", "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp, "%s %s", existing_username, existing_password) == 2)
    {
        if (strcmp(username, existing_username) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}


int check_password(char password[])
{
    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;
    int special = 0;

    if (strlen(password) < 8)
    {
        return 0;
    }

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }
    }

    if (uppercase == 1 && lowercase == 1 && digit == 1 && special == 1)
    {
        return 1;
    }

    return 0;
}


void sign_up()
{
    char username[50];
    char password[100];

    FILE *fp;

    int password_attempts;

    printf("\n");
    printf(" SIGN UP \n");

    /* Username must be unique */
    while (1)
    {
        printf("Enter username: ");
        scanf("%s", username);

        if (check_username(username) == 0)
        {
            break;
        }

        printf("Username already exists.\n");
        printf("Please enter another username.\n");
    }

    password_attempts = 0;

    while (password_attempts < 5)
    {
        printf("Enter password: ");
        scanf("%s", password);

        if (check_password(password) == 1)
        {
            break;
        }

        password_attempts++;

        printf("Invalid password.\n");
        printf("Password must contain minimum 8 characters,\n");
        printf("uppercase, lowercase, number and special character.\n");

        if (password_attempts == 5)
        {
            printf("TIME OUT\n");
            return;
        }
    }

    fp = fopen("usr_logins", "a");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf("Sign-up successful.\n");
}
void sign_in()
{
    char username[50];
    char password[100];

    FILE *fp;

    int attempts = 0;
    int found = 0;

    fp = fopen("usr_logins", "r");

    if (fp == NULL)
    {
        printf("No users found. Please sign-up first.\n");
        return;
    }

    while (attempts < 4)
    {
        printf("\n");
        printf("SIGN IN\n");

        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

	if (strcmp(username, "admin") == 0 &&
    strcmp(password, "Admin@123") == 0)
{
    printf("Login successful.\n");
    fclose(fp);
    admin_menu();
    return;
}

        rewind(fp);

        char existing_username[50];
        char existing_password[100];

        while (fscanf(fp, "%s %s",existing_username, existing_password) == 2)
        {
            if (strcmp(username, existing_username) == 0 && strcmp(password, existing_password) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
{
    printf("Login successful.\n");
    fclose(fp);

    if (strcmp(username, "admin") == 0)
    {
        admin_menu();
    }
    else
    {
        menu2();
    }

    return;
}

        attempts++;

        printf("Invalid username or password.\n");

        if (attempts == 4)
        {
            printf("You have reached max no.of attempts, please wait for 5 mins to login again.\n");
        }
    }

    fclose(fp);
}
