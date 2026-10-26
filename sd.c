
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void shift(char ch)
{
    stack[++top] = ch;
}

void reduce()
{
    int changed = 1;

    while(changed)
    {
        changed = 0;

        // E -> id
        if(top >= 0 && stack[top] == 'i')
        {
            stack[top] = 'E';
            printf("Reduce E -> id\n");
            changed = 1;
        }

        // E -> (E)
        if(top >= 2 &&
           stack[top-2] == '(' &&
           stack[top-1] == 'E' &&
           stack[top] == ')')
        {
            top -= 2;
            stack[top] = 'E';
            printf("Reduce E -> (E)\n");
            changed = 1;
        }

        // E -> E + E
        if(top >= 2 &&
           stack[top-2] == 'E' &&
           stack[top-1] == '+' &&
           stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            printf("Reduce E -> E + E\n");
            changed = 1;
        }

        // E -> E * E
        if(top >= 2 &&
           stack[top-2] == 'E' &&
           stack[top-1] == '*' &&
           stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            printf("Reduce E -> E * E\n");
            changed = 1;
        }
    }
}

int main()
{
    char input[100];
    int i, j;

    printf("Enter an expression: ");
    scanf("%s", input);

    for(i = 0; input[i] != '\0'; i++)
    {
        if(isalnum(input[i]))
        {
            shift('i');
            printf("Shift id\n");
        }
        else if(input[i] == '+' ||
                input[i] == '*' ||
                input[i] == '(' ||
                input[i] == ')')
        {
            shift(input[i]);
            printf("Shift %c\n", input[i]);
        }
        else
        {
            printf("Invalid Expression\n");
            return 0;
        }

        reduce();

        printf("Stack: ");

        for(j = 0; j <= top; j++)
        {
            printf("%c", stack[j]);
        }

        printf("\n");
    }

    if(top == 0 && stack[top] == 'E')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
