/* Merge two sorted array and create third array.
Input:
a1[] = {3,8,16,20,25}
a2[] = {4,10,12,22,23}

Output:
a3[] = {3,4,8,10,12,16,20,22,23,25}
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct test_array
{
    int arr[10]; // pointer to the actual array
    int size; // size of the array
    int length; // number of elements in an array
} array;

/* Swap API */
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void display(array A)
{
    printf("\nElements are: \n");

    for(int i = 0; i < A.length; ++i)
        printf("%d  ",A.arr[i]);

    printf("\n");
}

/* API to merge two sorted arrays and return third sorted array. */
array *mergeSortedArray(array *A1, array *A2)
{
    int index_A1 = 0, index_A2 = 0, index_A3 = 0;

    array *A3 = (array *)malloc(sizeof(array));

    while(index_A1 < A1->length && index_A2 < A2->length)
    {
        // compare elements of A1 and A2 and push the smaller element to A3.
        if(A1->arr[index_A1] < A2->arr[index_A2])
            A3->arr[index_A3++] = A1->arr[index_A1++];
        else
            A3->arr[index_A3++] = A2->arr[index_A2++];
    }

    // copy the remaining elements if any from A1 and A2 to A3.
    for(; index_A1 < A1->length; index_A1++)
        A3->arr[index_A3++] = A1->arr[index_A1];

    for(; index_A2 < A2->length; index_A2++)
        A3->arr[index_A3++] = A2->arr[index_A2];

    A3->length = A1->length + A2-> length;
    A3->size = 20; // value must be greater than or eqaul to A3->length.

    return A3;
}


int main(void)
{
    array A1 = {{3, 8, 16, 20, 25}, 20, 5};
    array A2 = {{4, 10, 12, 22, 23, 28}, 20, 6};
    array *A3;

    printf("Original Arrays\n");
    display(A1);
    display(A2);

    A3 = mergeSortedArray(&A1, &A2);
    display(*A3);

    return 0;
}
