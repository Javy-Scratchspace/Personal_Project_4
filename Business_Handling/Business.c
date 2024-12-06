// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"

// Print what's currently in the txt file for the business info
void businessPrint(Business *business) {

    FILE *file = fopen("Business_Inputs/Business_Info.txt", "r");
    char buffer[256];

    printf("\nHere is our business data:\n"); // Checkpoint (businessPrint)

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

// Edit any business information
void businessEdit(Business *business) {
    // Input code here
    
}

// Combine all functions into main function
int businessMain() {

    Business *business = (Business *)malloc(sizeof(Business));

    printf("\nThis program was made to access business information.\n");

    businessPrint(business);

    free(business);

    return 0;
}