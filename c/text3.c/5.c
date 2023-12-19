#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct {
    float items[max];
    int top;
} LINK;

void push(LINK *LINK, float value) {
    if (LINK->top == max - 1) {
        printf("LINK Overflow\n");
        return;
    }
    LINK->items[++LINK->top] = value;
}

float pop(LINK *LINK) {
    if (LINK->top == -1) {
        printf("LINK Underflow\n");
        exit(1);
    }
    return LINK->items[LINK->top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

float evaluate(char *word) {
    LINK LINK;
    LINK.top = -1;

    char *token = strtok(word, " ");
    while (token != NULL) {
        if (!is_operator(*token)) {
            push(&LINK, atof(token));
        } else {
            float operand2 = pop(&LINK);
            float operand1 = pop(&LINK);
            switch (*token) {
                case '+':
                    push(&LINK, operand1 + operand2);
                    break;
                case '-':
                    push(&LINK, operand1 - operand2);
                    break;
                case '*':
                    push(&LINK, operand1 * operand2);
                    break;
                case '/':
                    push(&LINK, operand1 / operand2);
                    break;
            }
        }
        token = strtok(NULL, " ");
    }

    return pop(&LINK);
}

int main() {
    char word[max];
    fgets(word, max, stdin);
    float result = evaluate(word);
    printf("%d", (int)result);
    return 0;
}
