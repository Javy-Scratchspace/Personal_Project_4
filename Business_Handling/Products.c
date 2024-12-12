// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data
// TODO: Make code frame

// gcc array_handling.c -o V1 && ./V1

#include <stdio.h>
#include <stdlib.h>
#include "Business_Header.h"

// Print what's currently in the txt file for the prouducts
Product *productPrint(Product *products, char *fileName) {

    char buffer[256];
    FILE *file = fopen(fileName, "r");

    printf("\nHere is our current available products:\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);

    return products; 
}

// Find any products
Product *productFind(Product *products) {
    // Input code here

    return products; 
}

// Add new products
Product *productAdd(Product *products) {
    // Input code here

    return products; 
}

// Remove products from the structure
Product *productRemove(Product *products) {
    // Input code here

    return products; 
}

// Edit any product information
Product *productEdit(Product *products) {
    // Input code here

    return products; 
}

// Update the txt file with any new information
Product *productUpdate(Product *products, char *fileName) {
    // Input code here

    return products; 
}

// Incorporate all product functions into productMain
int productMain() {

    Product *products = (Product *)malloc(sizeof(Product));
    char *fileName = "Business_Inputs/Products_Info.txt";

    printf("\nThis program was made to manage product information.\n");

    productPrint(products, fileName);

    free(products);

    return 0;
}