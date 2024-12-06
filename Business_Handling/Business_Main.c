// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"
#include "Clients.c"
#include "Products.c"
#include "Business.c"

int main(int argv, char **argc) {

    int access = 0;

    printf("\nThis program was made to manage business information and allow for allocation of funds.\n");

    while (1) {
        printf("\nWhat information would you like to access? Type 1 for business, 2 for clientelle, 3 for product, or 4 to quit.");
        printf("\n\tResponse: ");
        scanf("%d", &access); // Never forget the &

        if (access == 1) {
            businessMain();
            printf("\n");
        }
        else if (access == 2) {
            clientMain();
            printf("\n");
        }
        else if (access == 3){
            productMain();
            printf("\n");
        }
        else if (access == 4) {
            break;
        }
        else {printf("Cannot compute answer, try again.\n");}
    }

    printf("\nHave a great day!\n");

    return 0;
}