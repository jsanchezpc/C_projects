#include <stdio.h>
#include "inventory.h"

int main()
{
    int option;

    do
    {

        printf("\n+-- INVENTORY SYSTEM --+\n");
        printf("1. Add product\n");
        printf("2. Get product\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. List ALL products\n");
        printf("6. Exit\n");
        printf("Option: ");

        scanf("%d", &option);

        switch (option)
        {

        case 1:
            createProduct();
            break;

        case 2:
            readProduct();
            break;

        case 3:
            updateProduct();
            break;

        case 4:
            deleteProduct();
            break;

        case 5:
            listProducts();
            break;
        }

    } while (option != 6);

    return 0;
}