#include <stdio.h>

int n, m;
int e[20][20];
int trans[20][20][20];
int closure[20][20];
int visited[20];

void dfs(int s, int start)
{
    int i;
    visited[s] = 1;
    closure[start][s] = 1;

    for(i = 0; i < n; i++)
    {
        if(e[s][i] && !visited[i])
            dfs(i, start);
    }
}

int main()
{
    int i, j, k, l;
    int result[20];

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("Enter epsilon transition matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &e[i][j]);
        }
    }

    printf("Enter transition table:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("Number of transitions from state %d on symbol %d: ", i, j);
            int count;
            scanf("%d", &count);

            for(k = 0; k < count; k++)
            {
                int x;
                scanf("%d", &x);
                trans[i][j][x] = 1;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            closure[i][j] = 0;
            visited[j] = 0;
        }

        dfs(i, i);
    }

    printf("\nEpsilon Closures:\n");

    for(i = 0; i < n; i++)
    {
        printf("E-Closure(%d) = { ", i);

        for(j = 0; j < n; j++)
        {
            if(closure[i][j])
                printf("%d ", j);
        }

        printf("}\n");
    }

    printf("\nEquivalent NFA (Without Epsilon)\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            for(k = 0; k < n; k++)
                result[k] = 0;

            for(k = 0; k < n; k++)
            {
                if(closure[i][k])
                {
                    for(l = 0; l < n; l++)
                    {
                        if(trans[k][j][l])
                        {
                            int x;
                            for(x = 0; x < n; x++)
                            {
                                if(closure[l][x])
                                    result[x] = 1;
                            }
                        }
                    }
                }
            }

            printf("δ(%d,%d) = { ", i, j);

            for(k = 0; k < n; k++)
            {
                if(result[k])
                    printf("%d ", k);
            }

            printf("}\n");
        }
    }

    return 0;
}