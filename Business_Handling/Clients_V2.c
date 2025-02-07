// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"
#include "stringHandling.c"
#include "structHandling.c"


int freeClient(Client *clients) {

    if (clients == NULL) {
        return 0; 
    }

    freeClient(clients->nextClient);
    free(clients);

    return 0;
}

// Print client structs
void clientPrint(Client *clients) {
    
    int count = 0;
    
    if (clients == NULL) {
        printf("No more clients\n");
        return;
    }

    printf("Client ID: %d\n", clients->id);
    printf("\tName: %s %s\n", clients->firstName, clients->lastName);
    printf("\tLocation: %s\n", clients->location);
    printf("\tAge: %d\n", clients->age);
    printf("\tPayment Due: %.2f\n", clients->payment);
    printf("---------------------\n");

    // Recursive call and count the number of clients printed
    clientPrint(clients->nextClient);
}

// Print whatever is in the txt file
Client *getClient(Client *clients, char *fileName) {

    FILE *file = fopen(fileName, "r");
    char buffer[100];
    char firstName[100];
    char lastName[100];
    char location[100]; 
    int id; 
    int age; 
    float payment; 
    int lineCount = 0; 
    int clientCount = 0; 

    if (file == NULL) {
        printf("Cannot detect file, please try again");
        return NULL;
    }
    while (fscanf(file, "%s", buffer) != EOF) {

        printf("%s\n", buffer);

        if (lineCount == 0) {
            id = atoi(buffer);
        }
        else if (lineCount == 1) {
            strcpy(firstName, buffer);
        }
        else if (lineCount == 2) {
            strcpy(lastName, buffer);
        }
        else if (lineCount == 3) {
            strcpy(location, buffer);
        }
        else if (lineCount == 4) {
            age = atoi(buffer);
        }
        else if (lineCount == 5) {
            payment = atoi(buffer);
            clients = initializeClientStruct(clients, id, firstName, lastName, location, age, payment);
            lineCount = -1;
            clientCount+=1;
        }
        lineCount++;
    }

    printf("Clients: %d", clientCount);

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
    int clientCount = 0;

    clients = getClient(clients, fileName);

    printf("\nThis program was made to manage client information.\n");

    while (1) {

        printf("\n What would you like to do?");
        printf("\n\t1. print\n\t2. add\n\t3. remove\n\t4. edit\n\t5. update\n\t6. quit\n Response: ");
        scanf("%d", &access);

        if (access == 1) {
            printf("\n");
            printf("\nOur current clientelle are:\n"); // Checkpoint (clientPrint)
            clientPrint(clients);
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

    freeClient(clients);

    return 0;
}
