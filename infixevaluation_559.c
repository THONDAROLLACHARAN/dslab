#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c)
{
	if (top < MAX - 1)
	{
		stack[++top] = c;
	}
}

char pop()
{
	if (top >= 0)
	{
		return stack[top--];
	}
	return -1;
}

char peek()
{
	if (top >= 0)
	{
		return stack[top];
	}
	return -1;
}


int precedence(char op) 
{
	switch(op)
	{
		
		case '*':
		case '/':
		case '%': return 2;
		case '+':
		case '-': return 1;
		default: return 0;
	}
}


int isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}


void infixToPostfix(char infix[], char postfix[])
{
	int i, k = 0;
	char symbol;
	
	for (i = 0; i < strlen(infix); i++)
	{
		symbol = infix[i];
		
		
		if (isalnum(symbol))
		{
			postfix[k++] = symbol;
		}
		
		else if (symbol == '(')
		{
			push(symbol);
		}
		
		else if (symbol == ')')
		{
			while (top != -1 && peek() != '(')
			{
				postfix[k++] = pop();
			}
			pop();
		}
		
		else if(isOperator(symbol))
		{
			while (top != -1 && precedence(peek()) >= precedence(symbol))
			{
				postfix[k++] = pop();
			}
			push(symbol);
		}
	}
	
	
	while (top != -1)
	{
		postfix[k++] = pop();
	}
	
	postfix[k] = '\0';
}

int main()
{
	char infix[MAX], postfix[MAX];
	
	printf("Enter an infix expression: ");
	scanf("%s", infix);
	
	infixToPostfix(infix, postfix);
	
	printf("Postfix expression: %s\n",postfix);
	
	return 0;
}

