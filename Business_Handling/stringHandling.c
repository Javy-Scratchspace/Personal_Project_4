// stringHandling.c
// These functions were derived from online web searching, big props to www.w3schools.in for the help


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Business_Header.h"

char *removeStr(char *string, char *removeString) {

    char *updatedString = (char *)malloc(sizeof(char));
    int i, j, fsl, ssl, temp, chk = 0;
    
    /* Using the strlen function to calculate length of the given string. */
    fsl = strlen(string);
    ssl = strlen(removeString);

    /* Loop iteration to remove the second string from the first string. */
    for (i = 0; i < fsl; i++) {
        temp = i;
        for (j = 0; j < ssl; j++) {
        if (string[i] == removeString[j])
            i++;
        }
        chk = i - temp;
        if (chk == ssl) {
        i = temp;
        for (j = i; j < (fsl - ssl); j++)
            string[j] = string[j + ssl];
        fsl = fsl - ssl;
        string[j] = '\0';
        }
    }

    strcpy(updatedString, string);

    return updatedString;
}

// int main() {

//     char string[100] = "Hello World, How are yall doing", removeString[100] = "World";
//     char *updatedString = (char *)malloc(sizeof(char));

//     updatedString = removeStr(string, removeString);

//     printf("Updated String: %s", updatedString);

//     free(updatedString);

//     return 0;
// }