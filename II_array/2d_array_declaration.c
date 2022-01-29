/****************************************************************************
File name: 2d_array_declaration.c

Author: babajr
*****************************************************************************/


#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    /* Method 1: 2D array on stack */
    int a[3][4] = {{1, 2, 3, 4},
                   {4, 5, 6, 7},
                   {7, 8, 8, 9}};

    int i, j;

    printf("Display the array created on stack\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

    /* Method 2: 2D array with single pointer to array.
       Pointers will be created in stack and rows will be created in heap.*/
    int *b[3];
    b[0] = (int *)malloc(4 * sizeof(int));
    b[1] = (int *)malloc(4 * sizeof(int));
    b[2] = (int *)malloc(4 * sizeof(int));

    printf("Enter Elements\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            scanf("%d  ", &b[i][j]);
        }
    }

    printf("Display the array created on partially on heap\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d  ", b[i][j]);
        }
        printf("\n");
    }

    /* Method 3: Rows and columns are created in heap */
    int **c;
    c = (int **)malloc(3 * sizeof(int *));
    c[0] = (int *)malloc(4 * sizeof(int));
    c[1] = (int *)malloc(4 * sizeof(int));
    c[2] = (int *)malloc(4 * sizeof(int));

    printf("Enter Elements\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            scanf("%d  ", &c[i][j]);
        }
    }

    printf("Display the array created on heap\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d  ", c[i][j]);
        }
    }

    return 0;
}
