// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include "Business_Header.h"

// Print whatever is in the txt file
void clientPrint(Client *clients) {

    FILE *file = fopen("Business_Inputs/Clientelle_Info.txt", "r+");
    char buffer[256];

    printf("\nOur current clientelle are:\n"); // Checkpoint (client_print)

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

// Find clients in your structure
void clientFind(Client *clients) {
    // Input code here

}

// Add new clients to your structure
void clientAdd(Client *clients) {
    // Input code here

}

// Remove clients from your structure
void clientRemove(Client *clients) {
    // Input code here

}

// Edit client information
void clientEdit(Client *clients) {
    // Input code here

}

// Where all the functions are kept and ran
int clientMain() {

    Client *clients = (Client *)malloc(sizeof(Client));

    printf("\nThis program was made to manage client information.\n");

    clientPrint(clients);

    free(clients);

    return 0;
}
