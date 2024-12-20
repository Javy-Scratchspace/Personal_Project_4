// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"

// Used to establish a linear linked structured list. Uses clients struct as "head" move it forward to the next node in the structure (nextClient)
Client *initializeStruct(Client *clients, int id, char *name, char *location, int age, float payment) {

    Client *tempClient = (Client *)malloc(sizeof(Client));
    tempClient->id = id; 
    tempClient->name = name;
    tempClient->location = location; 
    tempClient->age = age; 
    tempClient->payment = payment; 
    tempClient->nextClient = NULL;

    // the head of the structure is clients
    if (clients == NULL) { 
        clients = tempClient; 
    }
    else {
        tempClient->nextClient = clients; 
        clients = tempClient; 
    }

    return clients; 
}

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
            buffer_ptr = buffer + strlen("\tClient ID: "); // Goes to buffer and skips "Client ID: " to get the info you want
            id = atoi(buffer_ptr);
        }
        else if (strstr(buffer, "Name: ") != NULL) {
            buffer_ptr = strtok(buffer, ": ");
            name = strtok(NULL, "\0");
        }
        else if (strstr(buffer, "Location: ") != NULL) {
            buffer_ptr = strtok(buffer, ": ");
            location = strtok(NULL, "\0");
        }
        else if (strstr(buffer, "Age: ") != NULL) {
            buffer_ptr = buffer + strlen("\tAge: ");
            age = atoi(buffer_ptr);
        }
        else if (strstr(buffer, "Payment Due: ") != NULL) {
            buffer_ptr = buffer + strlen("\tPayment Due: ");
            payment = atoi(buffer_ptr);
        }
        else if (strcmp(buffer, "\n") == 0) {
            clients = initializeStruct(clients, id, name, location, age, payment);
            printf("\nClient ID: %d\n\tName: %s %s\n\tPayment Due: %.2f", clients->id, clients->name, clients->payment);
        }
    }

    fclose(file);

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
