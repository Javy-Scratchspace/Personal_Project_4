// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"

// Print what's currently in the txt file for the business info
void businessPrint(Business *business, FILE *file) {

    char buffer[256]; // Used to read file inputs

    printf(" Here is our business data:\n"); // Checkpoint (businessPrint)

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "Client Count: ") != NULL) {
            business->client_count  = atoi(strtok(buffer, "Client Count: "));
        }
        else if (strstr(buffer, "Product Count: ") != NULL) {
            business->product_count  = atoi(strtok(buffer, "Product Count: ")); 
        }
        else if (strstr(buffer, "Business Equity: ") != NULL) {
            business->equity = atoi(strtok(buffer,"Business Equity: "));
        }
        else if (strstr(buffer, "Business Dues: ") != NULL) {
            business->dues = atoi(strtok(buffer, "Business Dues: "));
        }
    }

    printf("\tCurrent # of clients: %d\n", business->client_count);
    printf("\tCurrent # of products: %d\n", business->product_count);
    printf("\tCurrent equity: %d dollars\n", business->equity);
    printf("\tCurrent dues: %d dollars\n", business->client_count);

    fclose(file);
}

// Edit any business information
void businessEdit(Business *business) {
    // Input code here
    
}

// Update the txt file with the new information
void businessUpdate(Business *business, FILE *file) {
    // Input code here

}

// Combine all functions into main function
int businessMain() {

    Business *business = (Business *)malloc(sizeof(Business));
    FILE *file = fopen("Business_Inputs/Business_Info.txt", "r");
    int access; 

    printf("\n This program was made to access business information.");

    while (1) {
        
        printf("\n What would you like to do?");
        printf("\n\t1. print\n\t2. edit\n\t3. update\n\t4. quit\n Response: ");
        scanf("%d", &access);

        if (access == 1){
            printf("\n");
            businessPrint(business, file);
        }
        else if (access == 4) {
            break;
        }
    }

    printf("\n You have exited the business program, goodbye!");

    free(business);

    return 0;
}