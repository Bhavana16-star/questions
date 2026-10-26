
#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[50];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    push('$');

    strcat(exp, "$");

    for (i = 0; exp[i] != '$'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (top > 0 && stack[top] != '(')
                pop();

            if (top > 0)
                pop();
            else
            {
                printf("Invalid Expression\n");
                return 0;
            }
        }
        else if (exp[i] == '+' || exp[i] == '-' ||
                 exp[i] == '*' || exp[i] == '/')
        {
            while (top > 0 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(exp[i]))
            {
                pop();
            }

            push(exp[i]);
        }
        else if ((exp[i] >= 'a' && exp[i] <= 'z') ||
                 (exp[i] >= 'A' && exp[i] <= 'Z') ||
                 (exp[i] >= '0' && exp[i] <= '9'))
        {
            printf("%c", exp[i]);
        }
        else
        {
            printf("\nInvalid Expression\n");
            return 0;
        }
    }

    while (top > 0)
    {
        if (stack[top] == '(')
        {
            printf("\nInvalid Expression\n");
            return 0;
        }

        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
