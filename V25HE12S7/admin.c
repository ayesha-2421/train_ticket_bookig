#include <stdio.h>
#include <string.h>
#include "login.h"
#include "admin.h"
#include "structures.h"
#include "file.h"
void menu2();
void admin_menu();

void admin_menu()
{
    char choice;

    while (1)
    {
        printf("\n");
        printf(" ADMIN MENU \n");
        printf("A/a : Add train\n");
        printf("Q/q : Quit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        if (choice == 'A' || choice == 'a')
        {
            add_train();
        }
        else if (choice == 'Q' || choice == 'q')
        {
            printf("Admin logout successful.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
}

void add_train()
{
    Train train;
    Train existing_train;

    FILE *fp;

    int found;

    printf("\n");
    printf(" ADD TRAIN\n");

    printf("Enter train number: ");
    scanf("%d", &train.train_number);

    printf("Enter train name: ");
    scanf("%s", train.train_name);

    printf("Enter source: ");
    scanf("%s", train.source);

    printf("Enter destination: ");
    scanf("%s", train.destination);

    printf("Enter number of seats: ");
    scanf("%d", &train.no_of_seats);

    fp = fopen("train_info.txt", "r");

    if (fp != NULL)
    {
        found = 0;

        while (fscanf(fp, "%d %s %s %s %d",&existing_train.train_number,existing_train.train_name,existing_train.source,existing_train.destination,
                      &existing_train.no_of_seats) == 5)
        {
            if (existing_train.train_number == train.train_number)
            {
                printf("Train number already exists.\n");
                found = 1;
                break;
            }

            if (strcmp(existing_train.train_name, train.train_name) == 0)
            {
                printf("Train name already exists.\n");
                found = 1;
                break;
            }
        }

        fclose(fp);

        if (found == 1)
        {
            return;
        }
    }
save_train(train);
    printf("Train added successfully.\n");
}
