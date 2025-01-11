// structHandling.c

#include <stdio.h>
#include <stdlib.h>
#include "Business_Header.h"

typedef struct node{

    int data; 
    struct node *next; 

}node;

// Used to establish a linear linked structured list. Uses clients struct as "head" move it forward to the next node in the structure (nextProduct)
node *addEndNode(node *head, int data) {

    node *t;
    node *temp = (node *)malloc(sizeof(node)); 
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        t = head;
        while (t->next != NULL) {
            t = t->next; 
        }
        t->next = temp;
    }    

    return head;
}

Client *addClientInfo(int id, char *name, char *location, int age, float payment) {
    
    Client *clients = (Client *)malloc(sizeof(Client));

    clients->id = id; 
    clients->name = name;
    clients->location = location; 
    clients->age = age; 
    clients->payment = payment;
    clients->nextClient = NULL; 
    
    return clients; 
}

// Used to establish a linear linked structured list. Uses clients struct as "head" move it forward to the next node in the structure (nextClient)
Client *initializeClientStruct(Client *clients, int id, char *name, char *location, int age, float payment) {

    Client *tClient;
    Client *tempClient = addClientInfo(id, name, location, age, payment);

    // the head of the structure is clients
    if (clients == NULL) { 
        clients = tempClient; 
    }
    else {
        tClient = clients;
        while (tClient->nextClient != NULL) {
            tClient = tClient->nextClient; 
        }
        tClient->nextClient = tempClient;
    } 

    return clients; 
}

Product *addProductInfo(int id, char *name, int price) {

    Product *products = (Product *)malloc(sizeof(Product));

    products->id = id; 
    products->name = name;
    products->price = price; 
    products->nextProduct = NULL;

    return products; 
}

Product *initializeProductStruct(Product *products, int id, char *name, int price) {

    Product *tProduct;
    Product *tempProduct = addProductInfo(id, name, price);

    // the head of the structure is clients
    if (products == NULL) { 
        products = tempProduct; 
    }
    else {
        tProduct = products;
        while (tProduct->nextProduct != NULL) {
            tProduct = tProduct->nextProduct; 
        }
        tProduct->nextProduct = tempProduct;
    } 

    return products; 
}

// int main() {

//     node *head = NULL; 

//     addEndNode(head, 5);

//     addEndNode(head, 6);

//     while (head->next != NULL) {
//         printf("Num: %d\n", head->data);
//         head = head->next;
//     }

//     free(head);

//     return 0;
// }