// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"
#include "stringHandling.c"
#include "structHandling.c"

// Print whatever is in the txt file
Client *clientPrint(Client *clients, char *fileName) {

    FILE *file = fopen(fileName, "r");
    char *buffer_ptr; // NOTE: Never set this ptr to NULL, this does not allow for arithmetic processing.
    char buffer[256]; 
    char *name; 
    char *location; 
    int id; 
    int age; 
    float payment; 

    printf("\nOur current clientelle are:\n"); // Checkpoint (clientPrint)

    while (fgets(buffer, sizeof(buffer), file)) {
    
        if (strstr(buffer, "Client ID: ") != NULL) {
            char word[100] = "Client ID: ";
            buffer_ptr = removeStr(buffer, word);
            id = atoi(buffer_ptr);
        }
        else if (strstr(buffer, "Name: ") != NULL) {
            char word[100] = "\tName: ";
            name = removeStr(buffer, word);
        }
        else if (strstr(buffer, "Location: ") != NULL) {
            char word[100] = "\tLocation: ";
            location = removeStr(buffer, word);
        }
        else if (strstr(buffer, "Age: ") != NULL) {
            char word[100] = "Age: ";
            buffer_ptr = removeStr(buffer, word);
            age = atoi(buffer_ptr);
        }
        else if (strstr(buffer, "Payment Due: ") != NULL) {
            char word[100] = "Payment Due: ";
            buffer_ptr = removeStr(buffer, word);
            payment = atoi(buffer_ptr);
        }
        else if (strcmp(buffer, "\n") == 0) {
            clients = initializeClientStruct(clients, id, name, location, age, payment);
            printf("Client ID: %d\n\tName: %s\n\tLocation: %s\n\tAge: %d\n\tPayment Due: %.2f\n", clients->id, clients->name, clients->location, clients->age, clients->payment);
        }
    }

    fclose(file);

    free(buffer_ptr);

    return clients;
}

// Find clients in your structure
Client *clientFind(Client *clients) {
    // Input code here

    return clients;
}

// Add new clients to your structure
Client *clientAdd(Client *clients) {
    // Input code here

    return clients;
}

// Remove clients from your structure
Client *clientRemove(Client *clients) {
    // Input code here
    
    return clients; 
}

// Edit client information
Client *clientEdit(Client *clients) {
    // Input code here

    return clients;
}

// Update the txt file with any new information
Client *clientUpdate(Client *clients, char *fileName) {
    // Input code here

    return clients; 
}

// Where all the functions are kept and ran
int main() {

    Client *clients = NULL;
    char *fileName = "Business_Inputs/Clientelle_Info.txt"; 
    int access; 

    printf("\nThis program was made to manage client information.\n");

    while (1) {

        printf("\n What would you like to do?");
        printf("\n\t1. print\n\t2. add\n\t3. remove\n\t4. edit\n\t5. update\n\t6. quit\n Response: ");
        scanf("%d", &access);

        if (access == 1) {
            printf("\n");
            clientPrint(clients, fileName);
        }
        else if (access == 2) {
            printf("\n");
            clientFind(clients);
        }
        else if (access == 3) {
            printf("\n");
            clientRemove(clients);
        }
        else if (access == 4) {
            printf("\n");
            clientEdit(clients);
        }
        else if (access == 5) {
            printf("\n");
            clientUpdate(clients, fileName);
        }
        else if (access == 6) {
            break; 
        }
        else {
            printf("Cannot compute answer, try again.\n");
            main();
        }
    }

    free(clients);

    return 0;
}
