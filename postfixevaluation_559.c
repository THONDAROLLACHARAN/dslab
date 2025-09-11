#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
float stack[MAX];
int top = -1;
void push(float val);
float pop();
float evaluatePostfixExp(const char* exp);
int main() {
    char exp[MAX];
    float result;
	printf("Enter a postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';
	result = evaluatePostfixExp(exp);
    printf("Value of the postfix expression = %.2f\n", result);
	return 0;
}
float evaluatePostfixExp(const char* exp) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        // Skip whitespace
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            push((float)(exp[i] - '0'));
        } else {
            if (top < 1) {
                printf("STACK UNDERFLOW\n");
                exit(1);
            }
            op2 = pop();  // Second operand
            op1 = pop();  // First operand

            switch (exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': value = op1 / op2; break;
                case '%': value = (int)op1 % (int)op2; break;
                default:
                    printf("Invalid operator %c\n", exp[i]);
                    exit(1);
            }
            push(value);
        }
        i++;
    }

    return pop();
}

void push(float val) {
    if (top == MAX - 1) {
        printf("STACK OVERFLOW\n");
        exit(1);
    } else {
        stack[++top] = val;
    }
}
float pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

