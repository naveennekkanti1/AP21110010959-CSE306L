#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Variable {
    char name[50];
    char data_type[50];
    char size[50];
    char dimensions[50];
    char address[50];
    struct Variable* next;
};


struct Variable* head = NULL;


void add_variable(char name[], char data_type[], char size[], char dimensions[], char address[]) {
    struct Variable* new_variable = (struct Variable*)malloc(sizeof(struct Variable));
    strcpy(new_variable->name, name);
    strcpy(new_variable->data_type, data_type);
    strcpy(new_variable->size, size);
    strcpy(new_variable->dimensions, dimensions);
    strcpy(new_variable->address, address);
    new_variable->next = head;
    head = new_variable;
}

void display_symbol_table() {
    struct Variable* current = head;
    printf("\nSymbol Table:\n");
    printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "Name", "Type", "Size", "Dimensions", "Address");
    printf("--------------------------------------------------------------------------------------------\n");
    while (current != NULL) {
        printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", 
               current->name, current->data_type, current->size, current->dimensions, current->address);
        current = current->next;
    }
    printf("--------------------------------------------------------------------------------------------\n");
}

int main() {
    char choice;
    char name[50], data_type[50], size[50], dimensions[50], address[50];

    while (1) {
        printf("\nEnter '1' to add a variable, '2' to display the symbol table, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter the variable name: ");
                scanf("%s", name);
                printf("Enter the type (datatype, function, or array): ");
                scanf("%s", data_type);
                printf("Enter the size (if applicable): ");
                scanf("%s", size);
                if(data_type == "array"){
                	printf("Enter the dimensions (if it's an array, comma-separated): ");
                	scanf("%s", dimensions);
				}
				else{
					printf("-");
				}
                printf("Enter the address: ");
                scanf("%s", address);

                add_variable(name, data_type, size, dimensions, address);
                printf("Variable added to symbol table.\n");
                break;

            case '2':
                display_symbol_table();
                break;

            case 'q':
                while (head != NULL) {
                    struct Variable* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
