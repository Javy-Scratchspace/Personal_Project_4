// Author: Javier Cuevas
// Purpose: To use libraries from header files to access data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Business_Header.h"
#include "Clients.c"
#include "Products.c"
#include "Business.c"

//TODO: Edit business functions and set template for clientMain and productMain

int main(int argv, char **argc) {

    int access = 0;

    printf("\nThis program was made to manage business/client/product information.");

    while (1) {
        printf("\n What information would you like to access?\n\t1. business\n\t2. clientelle\n\t3. product\n\t4. quit.");
        printf("\n Response: ");
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