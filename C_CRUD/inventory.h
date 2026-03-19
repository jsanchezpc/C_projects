#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void createProduct();
void readProduct();
void updateProduct();
void deleteProduct();

void listProducts();

#endif