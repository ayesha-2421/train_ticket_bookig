 TRAIN TICKET BOOKING APP

 PROJECT DESCRIPTION

-> The Train Ticket Booking App is a C language project used to manage train information and passenger ticket reservations. Users can sign up, sign in, check train availability, reserve tickets, cancel tickets, and view booking details.

 FEATURES

- User sign-up and sign-in
- Unique username validation
- Password validation
- Limited login attempts
- Display available train information
- Add new train details through admin access
- Reserve train tickets
- Assign seat numbers to passengers
- Cancel booked tickets
- View passenger booking details
- Check train availability
- Allow ticket reservations only within the next three days
- Store train and passenger details in files
- Prevent duplicate train names and train numbers
- Preserve data after closing and restarting the application

 TECHNOLOGIES USED

- Programming Language: C
- Compiler: GCC
- Operating System: Ubuntu Linux
- Build Tool: Makefile and make
- Concepts Used: Structures, Pointers, Dynamic Memory Allocation, File Handling, and Singly Linked List (SLL)

  PROJECT FILES

(required.c files-11)
- main.c - Main function and application menu
- admin.c - Admin operations and adding trains
- admin.h - Admin function declarations
- login.c - User sign-up and sign-in operations
- login.h - Login function declarations
- train.c - Train-related operations
- train.h - Train function declarations
- train_sll.c - Singly linked list operations for trains
- train_sll.h - Train linked list declarations
- reservation.c - Ticket reservation
- reservation.h - Reservation-related declarations
- cancel_ticket.c - Ticket cancellation
- booking_details.c - Displays booking details
- check_journey_date.c - Checks journey date
- find_available_seat.c - Finds available seats
- file.c - File handling operations
- file.h - File handling declarations
- structures.h - Structure definitions
- train_info.txt - Stores train information
- passenger_info - Stores passenger booking information
- usr_logins - Stores user login information
- Makefile - Compiles the project
- README.txt - Project documentation

 COMPILATION

Open the terminal and navigate to the project directory.

Run the following command:

make

This command compiles the project using the Makefile.

 EXECUTION

After successful compilation, run the application using:

./train_app

 APPLICATION MENU

 MENU 1: USER LOGIN

1. Sign-up - Create a new user account.
2. Sign-in - Log in using an existing username and password.

 MENU 2: TRAIN BOOKING

- R/r - Reserve a ticket
- C/c - Cancel a ticket
- B/b - View booking details
- Q/q - Quit the application

 FILE HANDLING AND DATA STORAGE

The application uses separate files to store user login information, train information, and passenger booking details.

File handling is used to save and update information. Previously stored data remains available after restarting the application, provided the data files are preserved.

 CONCLUSION

The Train Ticket Booking App demonstrates the use of C programming, structures, pointers, dynamic memory allocation, file handling, and singly linked lists to manage train information and passenger reservations.
