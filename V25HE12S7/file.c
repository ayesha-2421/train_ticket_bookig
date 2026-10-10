#include <stdio.h>
#include "file.h"

void save_train(Train train)
{
    FILE *fp;

    fp = fopen("train_info.txt", "a");

    if (fp == NULL)
    {
        printf("Error: Unable to open train_info.txt.\n");
        return;
    }

    fprintf(fp, "%d %s %s %s %d\n",
            train.train_number,
            train.train_name,
            train.source,
            train.destination,
            train.no_of_seats);

    fclose(fp);
}

void syncfile(TrainNode *head)
{
    FILE *fp;
    TrainNode *temp;

    fp = fopen("train_info.txt", "w");

    if (fp == NULL)
    {
        printf("Error: Unable to open train_info.txt.\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fprintf(fp, "%d %s %s %s %d\n",
                temp->train.train_number,
                temp->train.train_name,
                temp->train.source,
                temp->train.destination,
                temp->train.no_of_seats);

        temp = temp->next;
    }

    fclose(fp);
}
