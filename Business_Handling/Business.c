// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"

/*
    In this code, the following is used
        1. Print
        2. Edit
        3. Update
    
    In order for this to work, you have to understand what is already in the text file. 
    First print your information.
    Then edit and update if necessary.
*/

// Print what's currently in the txt file for the business info
Business *businessPrint(Business *business, char *fileName) {

    char buffer[256]; // Used to read file inputs
    FILE *file = fopen(fileName, "r");

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
    printf("\tCurrent equity: %.2f dollars\n", business->equity);
    printf("\tCurrent dues: %.2f dollars\n", business->dues);
    printf("\tOverall amount of money in bank account: %d dollars\n", business->equity-business->dues);

    fclose(file);

    return business;
}

// Edit any business information
Business *businessEdit(Business *business) {
    
    int access;
    int input1;
    float input2; 
    char *edit; 

    printf(" What would you like to edit?\n\t1. Client Count\n\t2. Product Count\n\t3. Equity\n\t4. Dues\n Response: ");
    scanf("%d", &access);

    if (access == 1) { // Client Count
        printf("\n You are currently editing the number of clients. What is the updated client count?\n ");
        scanf("%d", &input1);
        edit = "Client Count";
        business->client_count = input1; 
    }
    else if (access == 2) { // Product Count
        printf("\n You are currently editing the number of products. What is the updated product count?\n ");
        scanf("%d", &input1);
        edit = "Product Count";
        business->product_count = input1;
    }
    else if (access == 3) { // Equity
        printf("\n You are currently editing the business equity. What is the updated equity?\n ");
        scanf("%f", &input2);
        edit = "Business Equity";
        business->equity = input2;
    }
    else if (access == 4) { // Dues
        printf("\n You are currently editing the business dues. What is the updated amount that the business owes?\n ");
        scanf("%f", &input2);
        edit = "Business Dues";
        business->dues = input2;
    }
    else {printf("Cannot compute answer, try again. ");}

    // Prints what you updated
    if (access == 1 || access == 2) {
        printf("\n Here is what you updated: %s -> %d\n", edit, input1);
    }
    else if (access == 3 || access == 4) {
        printf("\n Here is what you updated: %s -> %.2f\n", edit, input2);
    }
    else {printf("ERROR.\n");}

    return business;
}

// Update the txt file with the new information
Business *businessUpdate(Business *business, char *fileName) {

    FILE *file = fopen(fileName, "r");
    char buffer[256];
    int cCount, pCount;
    float bEquity, bDues;
    char *date; 

    // input date for record purposes
    printf(" Enter todays date:\n Response: ");
    scanf("%s", date);

    printf(" Currently updating business input file..."); // Checkpoint (businessUpdate)

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "Client Count: ") != NULL) {
            cCount = atoi(strtok(buffer, "Client Count: "));
        }
        else if (strstr(buffer, "Product Count: ") != NULL) {
            pCount = atoi(strtok(buffer, "Product Count: "));
        }
        else if (strstr(buffer, "Business Equity: ") != NULL) {
            bEquity = atoi(strtok(buffer, "Business Equity: "));
        } 
        else if (strstr(buffer, "Business Dues: ") != NULL) {
            bDues = atoi(strtok(buffer, "Business Dues: "));
        }
        else {continue;}
    }

    printf("\n Text File Readings:\n\tClient Count: %d\n\tProduct Count: %d\n\tEquity: %.2f\n\tDues: %.2f\n", cCount, pCount, bEquity, bDues);
    
    fclose(file);

    file = fopen(fileName, "w");
    
    printf("\n Current User Input:\n");

    // Update the text file officially, with date that the file was updated
    if (business->client_count != -1 && business->product_count != -1 && business->equity != -1 && business->dues != -1) {
        printf("\tClient Count: %d\n\tProduct Count: %d\n\tEquity: %.2f\n\tDues: %.2f\n", business->client_count, business->product_count, business->equity, business->dues);
        fprintf(file, "Date Updated: %s", date);
        fprintf(file, "\nClient Count: %d", business->client_count);
        fprintf(file, "\nProduct Count: %d", business->product_count);
        fprintf(file, "\nBusiness Equity: %.2f", business->equity);
        fprintf(file, "\nBusiness Dues: %.2f", business->dues);
    }
    else {printf("\tUser has not updated all information, be sure to run the print and then update your information\n");}

    fclose(file);

    return business;
}

// Combine all functions into main function
int businessMain() {

    Business *business = (Business *)malloc(sizeof(Business));
    char *fileName = "Business_Inputs/Business_Info.txt";
    int access; 

    // Establish your varable handling in your libraries
    business->client_count = -1;
    business->product_count = -1;
    business->equity = -1;
    business->dues = -1;

    printf("\n This program was made to access business information.");

    while (1) {
        
        printf("\n What would you like to do?");
        printf("\n\t1. print\n\t2. edit\n\t3. update\n\t4. quit\n Response: ");
        scanf("%d", &access);

        if (access == 1) {
            printf("\n");
            businessPrint(business, fileName);
        }
        else if (access == 2) {
            printf("\n");
            businessEdit(business);
        }
        else if (access == 3) {
            printf("\n");
            businessUpdate(business, fileName);
        }
        else if (access == 4) {
            break;
        }
        else {
            printf("Cannot compute answer, try again.\n");
            businessMain();
        }
    }

    printf("\n You have exited the business program, goodbye!");

    free(business);

    return 0;
}