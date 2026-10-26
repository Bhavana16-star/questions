#include <stdio.h>

int n;
int e[20][20];
int visited[20];

void epsilonClosure(int state)
{
    int i;
    visited[state] = 1;
    printf("%d ", state);

    for(i = 0; i < n; i++)
    {
        if(e[state][i] == 1 && visited[i] == 0)
        {
            epsilonClosure(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &e[i][j]);
        }
    }

    printf("\nEpsilon Closures\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            visited[j] = 0;
        }

        printf("E-Closure(%d) = { ", i);
        epsilonClosure(i);
        printf("}\n");
    }

    return 0;
}