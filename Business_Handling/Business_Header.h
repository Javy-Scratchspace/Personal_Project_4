#ifndef ARRAY_HANDLING_H_ // Always include these when handling header files
#define ARRAY_HANDLING_H_ 
#define CLIENTELLE 2000
#define PRODUCTS 100

typedef struct Client{

    int id;
    char *name; 
    char *location;
    int age;
    float payment;
    struct Client *nextClient;

}Client;

typedef struct Product{

    int id;
    char name[100];
    int price;
    struct Product *nextProduct; 

}Product;

typedef struct Business{

    int client_count; // Records how many clients there are
    int product_count; // Records how many products we offer
    float equity;
    float dues;

}Business;

// First the business protoypes
Business * businessPrint(Business *business, char *fileName);
Business * businessEdit(Business *business);
Business * businessUpdate(Business *business, char *fileName);
int businessMain();

// Next the client prototypes
Client * clientPrint(Client *clients, char *fileName);
Client * clientFind(Client *clients);
Client * clientAdd(Client *clients);
Client * clientRemove(Client *clients);
Client * clientEdit(Client *clients);
Client * clientUpdate(Client *clients, char *fileName);
int clientMain();

// Then the product prototypes
Product * productPrint(Product *products, char *fileName);
Product * productFind(Product *products);
Product * productAdd(Product *products);
Product * productRemove(Product *products);
Product * productEdit(Product *products);
Product * productUpdate(Product *products, char *fileName);
int productMain();

#endif // When doing header files, always start with ifndef and end with endif