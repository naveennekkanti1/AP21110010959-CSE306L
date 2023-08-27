//Implementing using Binary search tree method
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct SymbolNode {
    char name;
    void *address;
    char type[20];
    struct SymbolNode *left;
    struct SymbolNode *right;
};

struct SymbolNode *insertNode(struct SymbolNode *root, char name, void *address, const char *type) {
    if (root == NULL) {
        struct SymbolNode *newNode = (struct SymbolNode *)malloc(sizeof(struct SymbolNode));
        newNode->name = name;
        newNode->address = address;
        strcpy(newNode->type, type);
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (name < root->name) {
        root->left = insertNode(root->left, name, address, type);
    } else if (name > root->name) {
        root->right = insertNode(root->right, name, address, type);
    }

    return root;
}

struct SymbolNode *searchNode(struct SymbolNode *root, char name) {
    if (root == NULL || root->name == name) {
        return root;
    }

    if (name < root->name) {
        return searchNode(root->left, name);
    } else {
        return searchNode(root->right, name);
    }
}

int main() {
    int i = 0, j = 0, x = 0, n;
    struct SymbolNode *root = NULL;
    char ch, b[15], d[15], c;

    printf("Expression terminated by @:");
    while ((c = getchar()) != '@') {
        b[i] = c;
        i++;
    }
    n = i - 1;
    printf("Given Expression For Symbol Table Implementation:");
    i = 0;
    while (i <= n) {
        printf("%c", b[i]);
        i++;
    }

    printf("\nSymbol Table\n");
    printf("Symbol \t    address      \t    type");

    while (j <= n) {
        c = b[j];
        if (isalpha(c)) {
            void *p = malloc(sizeof(c));
            root = insertNode(root, c, p, "identifier");
            printf("\n%c \t %p \t identifier\n", c, p);
            x++;
            j++;
        } else {
            ch = c;
            if (ch == '+' || ch == '-' || ch == '*' || ch == '=') {
                void *p = malloc(sizeof(ch));
                root = insertNode(root, ch, p, "operator");
                printf("\n%c \t %p \t operator\n", ch, p);
                x++;
                j++;
            } else {
                j++;
            }
        }
    }

    return 0;
}

