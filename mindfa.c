#include<stdio.h>

int main()
{
    int n,m;
    int trans[20][20];
    int final[20];
    int mark[20][20]={0};
    int i,j,k,x,y;

    printf("Enter number of states: ");
    scanf("%d",&n);

    printf("Enter number of input symbols: ");
    scanf("%d",&m);

    printf("Enter transition table:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&trans[i][j]);

    printf("Enter final states (1 for final, 0 for non-final):\n");
    for(i=0;i<n;i++)
        scanf("%d",&final[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(final[i]!=final[j])
                mark[i][j]=1;
        }
    }

    int changed;

    do
    {
        changed=0;

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(mark[i][j]==0)
                {
                    for(k=0;k<m;k++)
                    {
                        x=trans[i][k];
                        y=trans[j][k];

                        if(x>y)
                        {
                            int t=x;
                            x=y;
                            y=t;
                        }

                        if(mark[x][y])
                        {
                            mark[i][j]=1;
                            changed=1;
                            break;
                        }
                    }
                }
            }
        }

    }while(changed);

    printf("\nEquivalent States:\n");

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mark[i][j]==0)
                printf("(%d,%d)\n",i,j);
        }
    }

    printf("\nMinimized DFA Transition Table\n");

    printf("State\t");

    for(i=0;i<m;i++)
        printf("%d\t",i);

    printf("Final\n");

    for(i=0;i<n;i++)
    {
        int flag=0;

        for(j=0;j<i;j++)
        {
            int a=j,b=i;

            if(a>b)
            {
                int t=a;
                a=b;
                b=t;
            }

            if(mark[a][b]==0)
            {
                flag=1;
                break;
            }
        }

        if(flag)
            continue;

        printf("%d\t",i);

        for(k=0;k<m;k++)
            printf("%d\t",trans[i][k]);

        printf("%d\n",final[i]);
    }

    return 0;
}