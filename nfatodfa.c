#include<stdio.h>
#include<string.h>

int n,m;
int trans[10][10];
int dfaStates[100];
int dfaTrans[100][10];
int front=0,rear=0;

int present(int x)
{
    int i;
    for(i=0;i<rear;i++)
        if(dfaStates[i]==x)
            return i;
    return -1;
}

int main()
{
    int i,j,k;

    printf("Enter number of NFA states: ");
    scanf("%d",&n);

    printf("Enter number of input symbols: ");
    scanf("%d",&m);

    printf("Enter transition table (bitmask values):\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&trans[i][j]);
        }
    }

    dfaStates[rear++]=1;

    while(front<rear)
    {
        int state=dfaStates[front];

        for(i=0;i<m;i++)
        {
            int next=0;

            for(j=0;j<n;j++)
            {
                if(state&(1<<j))
                    next|=trans[j][i];
            }

            int pos=present(next);

            if(pos==-1)
            {
                dfaStates[rear]=next;
                dfaTrans[front][i]=rear;
                rear++;
            }
            else
                dfaTrans[front][i]=pos;
        }

        front++;
    }

    printf("\nDFA States\n");

    for(i=0;i<rear;i++)
    {
        printf("D%d = { ",i);

        for(j=0;j<n;j++)
        {
            if(dfaStates[i]&(1<<j))
                printf("%d ",j);
        }

        printf("}\n");
    }

    printf("\nDFA Transition Table\n");

    printf("State");

    for(i=0;i<m;i++)
        printf("\t%d",i);

    printf("\n");

    for(i=0;i<rear;i++)
    {
        printf("D%d",i);

        for(j=0;j<m;j++)
            printf("\tD%d",dfaTrans[i][j]);

        printf("\n");
    }

    return 0;
}