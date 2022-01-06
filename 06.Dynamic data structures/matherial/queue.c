// Игнорировать устаревание getc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define MAX 10

char *p[MAX];
int in_pos;
int out_pos;

void qin(char *q) // overflow
{
    if (in_pos == MAX)
    {
        printf("Queue overflow\n");
        return;
    }
    p[in_pos] = q;
    in_pos++;
}

char *qout() // get element
{
    if (in_pos == out_pos)
    {
        printf("Queue empty\n");
        return '\0';
    }
    out_pos++;             // Смещение указателя
    return p[out_pos - 1]; // Вывод элемента на 1 меньше
}

void display() // output queue
{
    for (int j = out_pos; j < in_pos; j++)
        printf("%d %s\n", j + 1, p[j]);
}

void remove_el() // remove element
{
    char *p;
    if ((p = qout()) == NULL)
        return;
    printf("%s\n", p);
}

void new_el()
{
    char s[100], *p;
    do
    {
        printf("Write string ");
        gets(s);
        if (*s == 0)
            break;
        p = (char *)malloc(strlen(s) + 1);
        if (!p)
        {
            printf("Not mem\n");
            return;
        }
        strcpy(p, s);
        if (*s)
            qin(p);
    } while (*s);
}

int main()
{
    setlocale(0, "rus");
    char s[10];
    for (int j = 0; j < MAX; ++j)
        p[j] = NULL;

    for (;;)
    {
        printf("N - new element, D - display, R - remove element, Q - quit ");
        gets(s);
        *s = toupper(*s);
        switch (*s)
        {
        case 'N':
            new_el();
            break;
        case 'D':
            display();
            break;
        case 'R':
            remove_el();
            break;
        case 'Q':
            return 0;
        }
    }
}
