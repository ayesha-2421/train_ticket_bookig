
#include "structures.h"

TrainNode *create_train_node(Train train);
void insert_train(TrainNode **head, Train train);
TrainNode *search_train_number(TrainNode *head, int train_number);
TrainNode *search_train_name(TrainNode *head, char train_name[]);
void free_train_list(TrainNode *head);

TrainNode *load_trains();
void display_train_list(TrainNode *head);

