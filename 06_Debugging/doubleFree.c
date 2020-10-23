#include <stdio.h>
#include <stdlib.h>

enum {N = 20000};

int main(void)
{
    int *array;
    array = malloc(N * sizeof(array[0]));
    for (int i = 0; i < N; ++i)
    {
        array[i] = i;
    }
    for (int i = 0; i < N; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    int b = 5;
    printf("%d\n", b);
    free(array);
}
