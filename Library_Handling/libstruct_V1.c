// Author: Cuevas, Javier

//input structure thing through library.h
// NOTE: Add parameters for each function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "libstruct.h"

/*
The following represents the order of the functions based on a step-by-step ideology:

    Step 1. addBook() function
    Step 2. removeBook() function
    Step 3. checkoutBook() function
    Step 4. returnBook() function
    Step 5. printLibrary() function

This was implemented using printf() so that the user can see what the program is computing.
findBook() was left out of the "step-by-step" process because it is implemented within each function.
*/

// Find's books within library, used in other functions for easier and more legible code
// Code to be implemented in each function
int findBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {

    printf("Searching for book...\n"); // Checkpoint (find)

    // Runs through the library to find a similar book
    for (int i = 0; i < library->count; i++) {
        // Compares each library book to the book wanting to be found
        if (strcmp(library->library[i].title, bookTitle) == 0 && strcmp(library->library[i].author, bookAuthor) == 0 && library->library[i].year == bookYear && library->library[i].is_available == 1) {
            printf("Book with title %s, author%s, and year %d is found!\n", bookTitle, bookAuthor, bookYear);
            return 1;
        }
        else  if (i + 1 == library->count) {
            printf("Book not found.\n");
            return 0; // No Book found
        }
    }
}

// Step 1. Adds books to the library if books are not found
// Gave me struggles but learned how to use snprintf, a function that puts words together 
int addBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {

    // Does not have to iterate through library, uses findBook() to detect whether or not the book exists
    if (library->count >= MAX) {
        printf("The library is full. Cannot add more books.\n");
    }
    else if (findBook(library, bookTitle, bookAuthor, bookYear) == 1) {
        printf("Book with title %s, author%s, and year %d is already in the library.\n", bookTitle, bookAuthor, bookYear);
    }
    else {
        // Updates the library if there is no match
        printf("Adding book to library...\n"); // Checkpoint (add)
        strcpy(library->library[library->count].title, bookTitle);
        strcpy(library->library[library->count].author, bookAuthor);
        library->library[library->count].year = bookYear;
        library->library[library->count].is_available = 1;
        printf("Book with title %s, author %s, and year %d added to the library.\n", bookTitle, bookAuthor, bookYear);
        library->count++;
    }

    return 0; 
}

// Step 2. Removes a book from library after using findBook() to determine if it's in the library
// Simple to learn the applications of strtok
void removeBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {

    // This for loop is the only accepted repeated code for now because I cannot find a way to implement findBook
    for (int i = 0; i < library->count; i++) {
        // This portion takes parts of the library and separates them into title, author, and year
        // Should detect a book in library to be removed
        if (strcmp(library->library[i].title, bookTitle) == 0 && strcmp(library->library[i].author, bookAuthor) == 0 && library->library[i].year == bookYear && library->library[i].is_available == 1) {
            printf("Removing book from library...\n"); // Checkpoint (remove)
            for (int j = i; j < library->count; j++) {
                strcpy(library->library[j].title, library->library[j+1].title);
                strcpy(library->library[j].author, library->library[j+1].author);
                library->library[j].year = library->library[j+1].year;
                library->library[j].is_available = library->library[j+1].is_available;
            }
            library->count--;
            printf("Book with title %s, author%s, and year %d has been removed from the library.\n", bookTitle, bookAuthor, bookYear);
            break;
        }
    }
}

// Step3. Handles checking out the book. Must implement the disclaimer
// Uses findBook() to checkout books
int checkoutBook (Library *library, char *bookTitle, char *bookAuthor, int bookYear) {

    for (int i = 0; i < library->count; i++) {
        // Compares each library book to the book wanting to be found
        if (strcmp(library->library[i].title, bookTitle) == 0 && strcmp(library->library[i].author, bookAuthor) == 0 && library->library[i].year == bookYear && library->library[i].is_available == 1) {
            printf("Checking out book from library...\n"); // Checkpoint (checkout)
            library->library[i].is_available = 0;
            printf("Book with title %s, author%s, and %d is checked out\n", bookTitle, bookAuthor, bookYear);
        }
        else if (strcmp(library->library[i].title, bookTitle) == 0 && strcmp(library->library[i].author, bookAuthor) == 0 && library->library[i].year == bookYear && library->library[i].is_available == 0) {
            printf("Book with title %s, author%s, and year %d is already checked out.\n", bookTitle, bookAuthor, bookYear);
        }
    }

    return 0; 
}

// Step 4. Returns book, meaning the library count gets added one
// Same logic as checkout book, keeps book in library, removes count
int returnBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {

    for (int i = 0; i < library->count; i++) {
        // Compares each library book to the book wanting to be found
        if (strcmp(library->library[i].title, bookTitle) == 0 && strcmp(library->library[i].author, bookAuthor) == 0 && library->library[i].year == bookYear && library->library[i].is_available == 1) {
            printf("Book with title %s, author%s, and year %d is not checked out.\n", bookTitle, bookAuthor, bookYear);
        }
        else if (strcmp(library->library[i].title, bookTitle) == 0 && strcmp(library->library[i].author, bookAuthor) == 0 && library->library[i].year == bookYear && library->library[i].is_available == 0) {
            printf("Returning book to library...\n"); // Checkpoint (return)
            library->library[i].is_available = 1;
            printf("Book with title %s, author%s, and year %d is returned.\n", bookTitle, bookAuthor, bookYear);
        }
        else {
            printf("Book not found\n");
        }
    }

    return 0;
}

// Step 5. Prints library contents
// After doing remove/add, this seamed easier
int printLibrary(Library *library) {

    printf("Printing current library...\n"); // Checkpoint (print)

    if (library->count == 0) {
        printf("Library is empty.\n");
    }

    for (int i = 0; i < library->count; i++) {
        printf("Book with title %s, author%s, and year %d is in the library.\n", library->library[i].title, library->library[i].author, library->library[i].year);
    }

    printf("Library size: %d\n", library->count);

    return 0; 
}

// Reads through text files, detects add/remove/return/checkout/print
int main(int argc, char **argv) {

    // Establish library pointer
    Library *library = (Library *)malloc(sizeof(Library));

    // Establish from where you will be grabbing inputs from
    // 5 files of maximum 99 characters per file name
    char files[5][100] = {
        "autograder_inputs/input1.txt", 
        "autograder_inputs/input2.txt", 
        "autograder_inputs/input3.txt", 
        "autograder_inputs/input4.txt", 
        "autograder_inputs/input5.txt"
        }; // 5 words of maximum 99 characters per file name
    char *file_name;
    FILE *file;

    // Establish book information
    char *bookTitle; 
    char *bookAuthor;
    int bookYear;
    char buffer[256];
    library->count = 0;

    for (int i = 0; i < 5; i ++) {

        //open the file within the array
        file_name = files[i];
        file = fopen(file_name, "r");

        // Iterates through the file to get the desired book outputs
        while (fgets(buffer, sizeof(buffer),  file)) {
            // Add is step 1
            if (strcmp(buffer, "add\n") == 0) {
                if (fgets(buffer, sizeof(buffer),  file)) {
                    bookTitle = strtok(buffer, ",");
                    bookAuthor = strtok(NULL, ",");
                    bookYear = atoi(strtok(NULL, ",")); 
                    printf("\n1. Book input: %s detected.\n", buffer);
                    findBook(library, bookTitle, bookAuthor, bookYear);
                    addBook(library, bookTitle, bookAuthor, bookYear); // Includes checkpoint
                }
            }
            // Remove is step 2
            else if (strcmp(buffer, "remove\n") == 0) {
                if (fgets(buffer, sizeof(buffer),  file)) {
                    bookTitle = strtok(buffer, ",");
                    bookAuthor = strtok(NULL, ",");
                    bookYear = atoi(strtok(NULL, ","));
                    printf("\n2. Book input: %s detected.\n", buffer);
                    findBook(library, bookTitle, bookAuthor, bookYear);
                    removeBook(library, bookTitle, bookAuthor, bookYear); // Includes checkpoint
                }
            }
            // Checkout is step 3
            else if (strcmp(buffer, "checkout\n") == 0) {
                if (fgets(buffer, sizeof(buffer),  file)) {
                    bookTitle = strtok(buffer, ",");
                    bookAuthor = strtok(NULL, ",");
                    bookYear = atoi(strtok(NULL, ","));
                    printf("\n3. Book input: %s detected.\n", buffer);
                    findBook(library, bookTitle, bookAuthor, bookYear);
                    checkoutBook(library, bookTitle, bookAuthor, bookYear); // Includes checkpoint
                }
            }
            // Return is step 4
            else if (strcmp(buffer, "return") == 0) {
                if (fgets(buffer, sizeof(buffer),  file)) {
                    bookTitle = strtok(buffer, ",");
                    bookAuthor = strtok(NULL, ",");
                    bookYear = atoi(strtok(NULL, ","));
                    printf("\n4. Book input: %s detected.\n", buffer);
                    findBook(library, bookTitle, bookAuthor, bookYear);
                    returnBook(library, bookTitle, bookAuthor, bookYear); // Includes checkpoint
                }
            }
            // Print is step 5
            else if (strcmp(buffer, "print\n") == 0) {
                printf("\n5. Print library\n");
                printLibrary(library); // Includes checkpoint
            }
        }

        fclose(file);
    }

    return 0;
}