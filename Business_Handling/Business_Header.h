#ifndef ARRAY_HANDLING_H_ // Always include these when handling header files
#define ARRAY_HANDLING_H_ 
#define CLIENTELLE 2000
#define PRODUCTS 100

typedef struct Client{

    int id;
    char name[100];
    char location[1000];
    int age;
    int payment;
    struct Client *next;

}Client;

typedef struct Product{

    int id;
    char name[100];
    int price;
    struct Product *next; 

}Product;

typedef struct Business{

    int client_count; // Records how many clients there are
    int product_count; // Records how many products we offer
    int equity;
    int dues;

}Business;

// First the business protoypes
void businessPrint(Business *business, FILE *file);
void businessEdit(Business *business);
void businessUpdate(Business *business, FILE *file);
int businessMain();

// Next the client prototypes
void clientPrint(Client *clients, FILE *file);
void clientFind(Client *clients);
void clientAdd(Client *clients);
void clientRemove(Client *clients);
void clientEdit(Client *clients);
void clientUpdate(Client *clients, FILE *file);
int clientMain();

// Then the product prototypes
void productPrint(Product *products, FILE *file);
void productFind(Product *products);
void productAdd(Product *products);
void productRemove(Product *products);
void productEdit(Product *products);
void productUpdate(Product *products, FILE *file);
int productMain();

#endif // When doing header files, always start with ifndef and end with endif