#include <stdio.h>

int main()
{
    int a[10][10], sparse[20][3];
    int r, c, i, j, k = 1, count = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);

            if(a[i][j] != 0)
                count++;
        }
    }

    if((r * c - count) > count)
    {
        printf("\nSparse Matrix\n");

        // First row of triplet
        sparse[0][0] = r;
        sparse[0][1] = c;
        sparse[0][2] = count;

        // Store non-zero elements
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(a[i][j] != 0)
                {
                    sparse[k][0] = i;
                    sparse[k][1] = j;
                    sparse[k][2] = a[i][j];
                    k++;
                }
            }
        }

        printf("\nTriplet Representation:\n");

        for(i = 0; i <= count; i++)
        {
            printf("%d\t%d\t%d\n",
                   sparse[i][0],
                   sparse[i][1],
                   sparse[i][2]);
        }
    }
    else
    {
        printf("\nNot a Sparse Matrix");
    }

    return 0;
}