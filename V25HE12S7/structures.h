#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct train_info
{
    int train_number;
    char train_name[50];
    char source[50];
    char destination[50];
    int no_of_seats;
} Train;
typedef struct train_node
{
    Train train;
    struct train_node *next;
} TrainNode;

typedef struct seats_info
{
    int total_seats;
    int waiting_list;
    int current_booking_seat_number;
} Seats;
typedef struct passenger_info
{
    char username[50];
    int train_number;
    int journey_date;
    int seat_number;
    char passenger_name[50];
    int age;
    char gender;
} Passenger;

#endif
