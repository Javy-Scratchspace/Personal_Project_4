// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data
// TODO: Make code frame

// gcc array_handling.c -o V1 && ./V1

#include <stdio.h>
#include <stdlib.h>
#include "Business_Header.h"

// Print what's currently in the txt file for the prouducts
void productPrint(Product *products) {

    FILE *file = fopen("Business_Inputs/Products_Info.txt", "r+");
    char buffer[256];

    printf("\nHere is our current available products:\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

// Find any products
void productFind(Product *products) {
    // Input code here

}

// Add new products
void productAdd(Product *products) {
    // Input code here

}

// Remove products from the structure
void productRemove(Product *products) {
    // Input code here

}

// Edit any product information
void productEdit(Product *products) {
    // Input code here

}

// Incorporate all product functions into productMain
int productMain() {

    Product *products = (Product *)malloc(sizeof(Product));

    printf("\nThis program was made to manage product information.\n");

    productPrint(products);

    free(products);

    return 0;
}