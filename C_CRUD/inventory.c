#include <stdio.h>
#include <string.h>
#include "inventory.h"

void createProduct()
{
    FILE *file = fopen("products.dat", "ab");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    Product p;

    printf("ID: ");
    scanf("%d", &p.id);

    printf("Name: ");
    scanf("%49s", p.name);

    printf("Quantity: ");
    scanf("%d", &p.quantity);

    printf("Price: ");
    scanf("%f", &p.price);

    fwrite(&p, sizeof(Product), 1, file);

    fclose(file);

    printf("Product created correctly");
}

void readProduct()
{
    FILE *file = fopen("products.dat", "rb");

    if (file == NULL)
    {
        printf("No products\n");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    Product p;
    int found = 0;

    while (fread(&p, sizeof(Product), 1, file))
    {

        if (p.id == id)
        {
            printf("\nID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Quantity: %d\n", p.quantity);
            printf("Price: %.2f\n", p.price);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found)
        printf("Product not found\n");
}

void updateProduct()
{
    FILE *file = fopen("products.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    Product p;
    int found = 0;

    while (fread(&p, sizeof(Product), 1, file))
    {

        if (p.id == id)
        {
            found = 1;

            printf("New name: ");
            scanf("%49s", p.name);

            printf("New quantity: ");
            scanf("%d", &p.quantity);

            printf("New price: ");
            scanf("%f", &p.price);
        }

        fwrite(&p, sizeof(Product), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove("products.dat");
    rename("temp.dat", "products.dat");

    if (found)
        printf("Product updated\n");
    else
        printf("Product not found\n");
}

void deleteProduct()
{
    FILE *file = fopen("products.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Product p;
    int found = 0;

    while (fread(&p, sizeof(Product), 1, file))
    {

        if (p.id == id)
        {
            found = 1;
            continue; // 🔥 saltamos este producto
        }

        fwrite(&p, sizeof(Product), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove("products.dat");
    rename("temp.dat", "products.dat");

    if (found)
        printf("Product deleted\n");
    else
        printf("Product not found\n");
}

void listProducts()
{
    FILE *file = fopen("products.dat", "rb");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    Product p;

    while (fread(&p, sizeof(Product), 1, file))
    {

        printf("\nID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Quantity: %d\n", p.quantity);
        printf("Price: %.2f\n", p.price);
    }

    fclose(file);
}