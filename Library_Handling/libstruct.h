#ifndef LIBSTRUCT_H_
#define LIBSTRUCT_H_
#define MAX 2000

typedef struct Book {
    char title[1024];
    char author[1024];
    int year;
    int is_available;
}Book;

typedef struct Library {
    Book library[MAX + 1];
    int count;
    int bookYear;
}Library;

int addBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
void removeBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
int printLibrary(Library *library);
int findBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
int checkoutBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
int returnBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);

#endif 