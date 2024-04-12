#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Stack operations
#define MAX_STACK_SIZE 100
char stack[MAX_STACK_SIZE];
int top = -1;

void push(char symbol) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = symbol;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    } else {
        char symbol = stack[top];
        top--;
        return symbol;
    }
}

// Function to simulate PDA
bool isAccepted(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '0') {
            push('0');
        } else if (input[i] == '1') {
            if (top == -1) {
                return false; // More 1s than 0s, reject
            }
            pop();
        } else {
            printf("Invalid input!\n");
            return false;
        }
    }
    return (top == -1); // Stack should be empty at the end for equal number of 0s and 1s
}

int main() {
    char input[100];
    printf("Enter a string of 0s and 1s: ");
    scanf("%s", input);
    
    if (isAccepted(input)) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }
    
    return 0;
}
