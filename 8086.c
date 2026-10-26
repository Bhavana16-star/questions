
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char lhs[20], a[20], b[20], op;
    char line[100];

    printf("Enter number of statements: ");
    scanf("%d", &n);

    getchar();

    printf("\n8086 Assembly Code:\n");

    for(i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);

        
        if(sscanf(line, "%s = %s %c %s",
                  lhs, a, &op, b) == 4)
        {
            printf("MOV AX, %s\n", a);

            if(op == '+')
                printf("ADD AX, %s\n", b);

            else if(op == '-')
                printf("SUB AX, %s\n", b);

            else if(op == '*')
            {
                printf("MOV BX, %s\n", b);
                printf("MUL BX\n");
            }

            else if(op == '/')
            {
                printf("MOV BX, %s\n", b);
                printf("MOV DX, 0\n");
                printf("DIV BX\n");
            }

            printf("MOV %s, AX\n\n", lhs);
        }

        
        else if(sscanf(line, "%s = %s", lhs, a) == 2)
        {
            printf("MOV AX, %s\n", a);
            printf("MOV %s, AX\n\n", lhs);
        }
    }

    return 0;
}

