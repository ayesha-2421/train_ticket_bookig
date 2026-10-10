#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train_sll.h"

TrainNode *create_train_node(Train train)
{
    TrainNode *new_node;

    new_node = (TrainNode *)malloc(sizeof(TrainNode));

    if (new_node == NULL)
    {
        return NULL;
    }

    new_node->train = train;
    new_node->next = NULL;

    return new_node;
}

void insert_train(TrainNode **head, Train train)
{
    TrainNode *new_node;
    TrainNode *temp;

    new_node = create_train_node(train);

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

TrainNode *search_train_number(TrainNode *head, int train_number)
{
    TrainNode *temp;

    temp = head;

    while (temp != NULL)
    {
        if (temp->train.train_number == train_number)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

TrainNode *search_train_name(TrainNode *head, char train_name[])
{
    TrainNode *temp;

    temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->train.train_name, train_name) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void free_train_list(TrainNode *head)
{
    TrainNode *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
TrainNode *load_trains()
{
    FILE *fp;
    Train train;
    TrainNode *head;

    head = NULL;

    fp = fopen("train_info.txt", "r");

    if (fp == NULL)
    {
        return NULL;
    }

    while (fscanf(fp, "%d %s %s %s %d",
                  &train.train_number,
                  train.train_name,
                  train.source,
                  train.destination,
                  &train.no_of_seats) == 5)
    {
        insert_train(&head, train);
    }

    fclose(fp);

    return head;
}

void display_train_list(TrainNode *head)
{
    TrainNode *temp;

    temp = head;

    printf("\n");
    printf("AVAILABLE TRAINS\n");
    printf("\n");

    while (temp != NULL)
    {
        printf("Train Number : %d\n", temp->train.train_number);
        printf("Train Name   : %s\n", temp->train.train_name);
        printf("Source       : %s\n", temp->train.source);
        printf("Destination  : %s\n", temp->train.destination);
        printf("Seats        : %d\n", temp->train.no_of_seats);
        printf("\n");

        temp = temp->next;
    }
}
