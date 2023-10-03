#include <stdio.h>
#include <string.h>

int S();
int L();
int Ldash();

char *ip;
char string[50];

int main() {
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");
    if (S() && *ip == '\0') {
        printf("\n--------------------------------\n");
        printf("String is successfully parsed\n");
    } else {
        printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
    }
}

int S() {
    printf("%s\tS->(L) \n", ip);
    if (*ip == '(') {
        ip++;
        if (L()) {
            if (*ip == ')') {
                ip++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (*ip == 'a' || *ip == ';') {
        ip++;
        return 1;
    } else {
        return 0;
    }
}

int L() {
    printf("%s\tL->SL' \n", ip);
    if (S()) {
        if (Ldash()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int Ldash() {
    if (*ip == ',') {
        printf("%s\tL'->,S \n", ip);
        ip++;
        if (S()) {
            if (Ldash()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        printf("%s\tL'->e \n", ip);
        return 1;
    }
}
