#include <stdio.h>
#include <stdlib.h>

#define MAX1 10
#define MAX2 10

struct sparse
{
    int *sp;
    int row;
};



void createSparse(struct sparse *p)
{
    int i, j, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    p->sp = (int *)calloc(MAX1 * MAX2, sizeof(int));

    for(int k = 0; k < n; k++)
    {
        printf("Enter row column and for non-zero element %d:\n", k + 1);
        scanf("%d %d", &i, &j);
        if (i >= 0 && i < MAX1 && j >= 0 && j < MAX2)
        {
            printf("Enter the value: ");
            scanf("%d", &p->sp[i * MAX2 + j]);
        }
        else
        {
            printf("Invalid row or column");
            exit(1);
        }
    }
    printf("\n");
}


void initsparse(struct sparse *p)
{
    p->sp = NULL;
    p->row = 0;
}

void display(struct sparse p)
{
    for (int i = 0; i < MAX1; i++)
    {
        for (int j = 0; j < MAX2; j++)
        {
            printf("%d  ", *(p.sp + i * MAX2 + j));
        }
        printf("\n");
    }
    printf("\n");
}






int mainn()
{
    struct sparse test;

    initsparse(&test);
    createSparse(&test);

    printf("Sparse Matrix required is :\n");
    display(test);
    return 0;
}
