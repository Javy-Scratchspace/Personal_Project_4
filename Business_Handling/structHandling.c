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

// Add clientelle 
Client *addClientInfo(int id, char *firstName, char* lastName, char *location, int age, float payment) {
    
    Client *clients = malloc(sizeof(Client));

    clients->id = id; 
    strcpy(clients->firstName, firstName);
    strcpy(clients->lastName, lastName);
    strcpy(clients->location, location); 
    clients->age = age;
    clients->payment = payment;
    clients->nextClient = NULL; 
    
    return clients; 
}

// Used to establish a linear linked structured list. Uses clients struct as "head" move it forward to the next node in the structure (nextClient)
Client *initializeClientStruct(Client *clients, int id, char *firstName, char* lastName, char *location, int age, float payment) {

    Client *current; 

    if (clients == NULL) {
        clients = addClientInfo(id, firstName, lastName, location, age, payment);
    }
    else {
        current = clients;
        while (current != NULL) {
            current = current->nextClient; 
        }
        current = addClientInfo(id, firstName, lastName, location, age, payment);
        clients->nextClient = current;
    }

    return clients; 
}

// Add product info
Product *addProductInfo(int id, char *name, int price) {

    Product *products = (Product *)malloc(sizeof(Product));

    products->id = id; 
    products->name = name;
    products->price = price; 
    products->nextProduct = NULL;

    return products; 
}

// Create a singly linked that only goes one way and updates accordingly
Product *initializeProductStruct(Product *products, int id, char *name, int price) {

    Product *tProduct;
    Product *tempProduct = addProductInfo(id, name, price);

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