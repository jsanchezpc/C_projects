#include <stdio.h>
#include <string.h>
#include "inventory.h"

void createProduct() {
    FILE *file = fopen("products.dat", "ab");

    Product p;

    printf("ID: ");
    scanf("%d", &p.id);

    printf("Name: ");
    scanf("%s", p.name);

    printf("Quantity: ");
    scanf("%d", p.quantity);

    printf("Price: ");
    scanf("%f", p.price);
    


}