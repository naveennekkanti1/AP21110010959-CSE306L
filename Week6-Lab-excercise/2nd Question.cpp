#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//E'=A
//T'=B
int i = 0, top = 0;
char stack[20], ip[20];

void push(char c) {
    if (top >= 20)
        printf("Stack Overflow");
    else
        stack[top++] = c;
}

void pop(void) {
    if (top < 0)
        printf("Stack underflow");
    else
        top--;
}

void error(void) {
    printf("\n\nSyntax Error!!!! String is invalid\n");
    exit(0);
}

int main() {
    int n;

    printf("Enter the string to be parsed:\n");
    scanf("%s", ip);
    n = strlen(ip);
    ip[n] = '$';
    ip[n + 1] = '\0';
    push('$');
    push('E');
    while (ip[i] != '\0') {
        if (ip[i] == '$' && stack[top - 1] == '$') {
            printf("\n\nSuccessful parsing of string\n");
            return 1;
        } else if (ip[i] == stack[top - 1]) {
            printf("\nMatch of %c occurred ", ip[i]);
            i++;
            pop();
        } else {
            if (stack[top - 1] == 'E' && (ip[i] == 'd' || ip[i] == '(')) {
                printf("\nE -> TE'");
                pop();
                push('A');
                push('T');
            } else if (stack[top - 1] == 'A' && ip[i] == '+') {
                printf("\nE'->+TE'");
                pop();
                push('A');
                push('T');
                push('+');
            } else if (stack[top - 1] == 'A' && ip[i] == ')') {
                printf("\nE' -> epsilon");
                pop();
            } else if (stack[top - 1] == 'A' && ip[i] == '$') {
                printf("\nE' -> epsilon");
                pop();
            } else if ((stack[top - 1] == 'T' && ip[i] == 'd') || (stack[top - 1] == 'T' && ip[i] == '(')) {
                printf("\nT -> FT'");
                pop();
                push('B');
                push('F');
            } else if (stack[top - 1] == 'B' && ip[i] == '*') {
                printf("\nT'->*FT'");
                pop();
                push('B');
                push('F');
                push('*');
            } else if ((stack[top - 1] == 'B' && ip[i] == '+') || (stack[top - 1] == 'B' && ip[i] == ')') ||
                       (stack[top - 1] == 'B' && ip[i] == '$')) {
                printf("\nT'-> epsilon");
                pop();
            } else if ((stack[top - 1] == 'F' && ip[i] == 'd') || (stack[top - 1] == 'F' && ip[i] == '(')) {
                printf("\nF->%c", ip[i]);
                pop();
                push(ip[i]);
            } else {
                error();
            }
        }
    }
    return 0;
}

