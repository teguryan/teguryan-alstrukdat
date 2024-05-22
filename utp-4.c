#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, char newValue) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = newValue;
    } else {
        printf("Stack penuh!\n");
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack kosong!\n");
        return '\0'; 
    }
}

void reverseString(char str[]) {
    Stack stack;
    init(&stack);

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    printf("String yang terbalik: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char string[MAX];
    printf("Masukkan sebuah string: ");
    fgets(string, MAX, stdin);
    string[strcspn(string, "\n")] = '\0'; 

    printf("String asli: %s\n", string);
    reverseString(string);

    return 0;
}