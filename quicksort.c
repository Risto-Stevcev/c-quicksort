#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

void
print_arr (int *arr, int arrlen)
{
    printf("%d", arr[0]);
    for (int i = 1; i < arrlen; i++)
        printf(", %d", arr[i]);
    printf("\n");
}

void
swap ( int *arr, int a, int b )
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int
partition ( int *arr, int left, int right, int pivotidx )
{
    int pivot = arr[pivotidx];
    swap( arr, right, pivotidx );

    for (int i = left; i < right; i++) {
        if (arr[i] < pivot) {
            swap( arr, i, left );
            left++;
        }
    }

    swap( arr, left, right );
    return left;
}

unsigned int
randr (unsigned int min, unsigned int max)
{
    double scaled = (double)rand()/RAND_MAX;
    return scaled*(max - min + 1) + min;
}

void
__quick_sort__ ( int *arr, int left, int right )
{
    if (right > left) {
        int pivotidx = randr(left, right);
        pivotidx = partition( arr, left, right, pivotidx );
        __quick_sort__( arr, left, pivotidx );
        __quick_sort__( arr, pivotidx+1, right );
    }
}

int *
quick_sort ( int *arr, int len )
{
    srand(time(NULL));
    __quick_sort__( arr, 0, len-1 );
    return arr;
}
