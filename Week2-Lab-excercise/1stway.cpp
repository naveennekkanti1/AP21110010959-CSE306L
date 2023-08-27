//Normal way of Implementation
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() {
    int i = 0, j = 0, x = 0, n;
    void *p, *add[5];
    char ch, srch, b[15], d[15], c;

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
            p = malloc(sizeof(c)); 
            add[x] = p;
            d[x] = c;
            printf("\n%c \t %p \t identifier\n", c, p);  
            x++;
            j++;
        } else {
            ch = c;
            if (ch == '+' || ch == '-' || ch == '*' || ch == '=') {
                p = malloc(sizeof(ch));  
                add[x] = p;
                d[x] = ch;
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

