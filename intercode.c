
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char expr[100];
char postfix[100];
char opstack[100];

char values[100][20];

int top = -1;
int vtop = -1;
int tempno = 0;

int precedence(char op)
{
    if(op == '*' || op == '/')
        return 2;

    if(op == '+' || op == '-')
        return 1;

    return 0;
}

void infixToPostfix()
{
    int i, j = 0;
    char ch;

    for(i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            opstack[++top] = ch;
        }
        else if(ch == ')')
        {
            while(top != -1 && opstack[top] != '(')
                postfix[j++] = opstack[top--];

            if(top != -1)
                top--;
        }
        else
        {
            while(top != -1 &&
                  opstack[top] != '(' &&
                  precedence(opstack[top]) >= precedence(ch))
            {
                postfix[j++] = opstack[top--];
            }

            opstack[++top] = ch;
        }
    }

    while(top != -1)
        postfix[j++] = opstack[top--];

    postfix[j] = '\0';
}

void generateCode()
{
    int i;
    char op1[20], op2[20];
    char result[20];
    char op;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isalnum(postfix[i]))
        {
            values[++vtop][0] = postfix[i];
            values[vtop][1] = '\0';
        }
        else
        {
            op = postfix[i];

            strcpy(op2, values[vtop--]);
            strcpy(op1, values[vtop--]);

            tempno++;

            sprintf(result, "t%d", tempno);

            printf("%s = %s %c %s\n",
                   result, op1, op, op2);

            strcpy(values[++vtop], result);
        }
    }
}

int main()
{
    printf("Enter an expression: ");
    scanf("%s", expr);

    infixToPostfix();

    printf("\nThree Address Code:\n");

    generateCode();

    return 0;
}
