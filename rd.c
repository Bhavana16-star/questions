#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

void E();
void E1();
void T();
void T1();
void F();

void E()
{
    T();
    E1();
}

void E1()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        E1();
    }
}

void T()
{
    F();
    T1();
}

void T1()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        T1();
    }
}

void F()
{
    if (input[pos] == 'i')
    {
        pos++;
    }
    else if (input[pos] == '(')
    {
        pos++;
        E();

        if (input[pos] == ')')
            pos++;
        else
        {
            printf("Invalid Expression");
            return;
        }
    }
    else
    {
        printf("Invalid Expression");
        return;
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%99s", input);

    E();

    if (input[pos] == '\0')
        printf("Valid Expression");
    else
        printf("Invalid Expression");

    return 0;
}