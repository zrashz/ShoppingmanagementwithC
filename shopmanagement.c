#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PRODUCTS 100

// Structures for User and Product
typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

typedef struct {
    int id;
    char name[50];
    float price;
    int stock;
} Product;

// Arrays to store users and products
User users[MAX_USERS];
Product products[MAX_PRODUCTS];
int userCount = 0;
int productCount = 0;

// Function prototypes
void addUser();
void viewUsers();
void deleteUser();
void addProduct();
void viewProducts();
void deleteProduct();
void mainMenu();

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;
    do {
        printf("\n=== Clothing Shop Management System ===\n");
        printf("1. User Management\n");
        printf("2. Product Management\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- User Management ---\n");
                printf("1. Add User\n");
                printf("2. View Users\n");
                printf("3. Delete User\n");
                printf("Enter your choice: ");
                int userChoice;
                scanf("%d", &userChoice);
                if (userChoice == 1) addUser();
                else if (userChoice == 2) viewUsers();
                else if (userChoice == 3) deleteUser();
                else printf("Invalid choice!\n");
                break;

            case 2:
                printf("\n--- Product Management ---\n");
                printf("1. Add Product\n");
                printf("2. View Products\n");
                printf("3. Delete Product\n");
                printf("Enter your choice: ");
                int productChoice;
                scanf("%d", &productChoice);
                if (productChoice == 1) addProduct();
                else if (productChoice == 2) viewProducts();
                else if (productChoice == 3) deleteProduct();
                else printf("Invalid choice!\n");
                break;

            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}

// User Management Functions
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User list is full!\n");
        return;
    }

    User newUser;
    newUser.id = userCount + 1;
    printf("Enter user name: ");
    scanf("%s", newUser.name);
    printf("Enter user email: ");
    scanf("%s", newUser.email);

    users[userCount] = newUser;
    userCount++;
    printf("User added successfully!\n");
}

void viewUsers() {
    if (userCount == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\n--- User List ---\n");
    int i;
    for ( i = 0; i < userCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

void deleteUser() {
    if (userCount == 0) {
        printf("No users to delete.\n");
        return;
    }

    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    int i,j;
    for ( i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            found = 1;
            for ( j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("User with ID %d not found.\n", id);
    }
}

// Product Management Functions
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product list is full!\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product stock: ");
    scanf("%d", &newProduct.stock);

    products[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products to display.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    int i;
    for ( i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Stock: %d\n",
               products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void deleteProduct() {
    if (productCount == 0) {
        printf("No products to delete.\n");
        return;
    }

    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    int i,j;
    for (i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            for ( j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}
