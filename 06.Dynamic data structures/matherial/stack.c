#include <stdio.h>
#include <stdlib.h>
#define MAX 80
int stack[MAX];
int top;

void push()
{
	int num;
	if (top >= MAX)
	{
		printf("Stack overflow!!!\n");
		return;
	}
	printf("Write element ");
	scanf("%d", &num);

	stack[top] = num;
	top++;
}

int pop()
{
	top--;
	if (top < 0)
	{
		printf("Stack empty\n");
		return 0;
	}
	return stack[top];
}

void display()
{
	for (int j = 0; j < top; j++)
		printf("%d ", stack[j]);
	printf("\n");
}

int main()
{
	setlocale(0, "rus");

	char s[10];

	for (;;)
	{
		printf("N - new element, D - display, R - remove, Q - exit \n");
		gets(s);
		*s = toupper(*s);
		switch (*s)
		{
		case 'N':
			push();
			break;
		case 'D':
			display();
			break;
		case 'R':
			printf("%d\n", pop());
			break;
		case 'Q':
			return 0;
		}
	}

	return 0;
}
