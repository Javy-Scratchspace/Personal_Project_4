// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"

// Print whatever is in the txt file
Client *clientPrint(Client *clients, char *fileName) {

    char buffer[256];
    Client *tempClient = (Client *)malloc(sizeof(Client));
    FILE *file = fopen(fileName, "r");

    tempClient->nextClient = NULL; 

    printf("\nOur current clientelle are:\n"); // Checkpoint (client_print)

    while (fgets(buffer, sizeof(buffer), file)) {

        if (clients == NULL) {
            clients = tempClient;
        }
        else {
            tempClient->nextClient = clients;
            clients = tempClient;
        }
    
        if (strstr(buffer, "Client ID: ") != NULL) {
            clients->id = atoi(strtok(buffer, "Client ID: "));
        }
        else if (strstr(buffer, "Name: ") != NULL) {
            strcpy(clients->name, strtok(buffer, "Name: "));
        }
        else if (strstr(buffer, "Location: ") != NULL) {
            strcpy(clients->location, strtok(buffer, "Location: "));
        }
        else if (strstr(buffer, "Age: ") != NULL) {
            clients->age = atoi(strtok(buffer, "Age: "));
        }
        else if (strstr(buffer, "Payment Due: ") != NULL) {
            clients->payment = atoi(strtok(buffer, "Payment Due: "));
        }

        printf(" Client ID: %d\n\tClient Name: %s\n\tClient Location: %s\n\tClient Age: %d\n\tClient Payment: %.f\n", clients->id, clients->name, clients->location, clients->age, clients->payment);
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
int clientMain() {

    Client *clients = NULL;
    char *fileName = "Business_Inputs/Clientelle_Info.txt"; 

    printf("\nThis program was made to manage client information.\n");

    clientPrint(clients, fileName);

    free(clients);

    return 0;
}
