#include <stdio.h>
#include "train.h"
#include "train_sll.h"

void display_trains()
{
    TrainNode *head;

    head = load_trains();

    if (head == NULL)
    {
        printf("No train information available.\n");
        return;
    }

    display_train_list(head);

    free_train_list(head);
}

