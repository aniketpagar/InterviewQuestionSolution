/****************************************************************************
File name: swap_two_columns_2d_arr.cpp

Author: babajr
*****************************************************************************/


/*
Swap two columns in given 2D array.

Input: {{1,5,1,10}, {2,10,3,4}, {1,10,10,7}} and
        swap 0th column to 3rd row.

Output: {{10,5,1,1}, {4,10,3,2}, {7,10,10,1}}

*/


#include<bits/stdc++.h>
using namespace std;

#define SIZE_COL    3
#define SIZE_ROW    3

void printArray(int matrix[SIZE_ROW][SIZE_COL], int rowSize, int colSize)
{
    for(int row = 0; row < rowSize; ++row)
    {
        for(int col = 0; col < colSize; ++col)
            cout << matrix[row][col] << " ";
        cout << endl;
    }

}


void swapColumns(int arr[SIZE_ROW][SIZE_COL], int original_col, int updated_col)
{
    for(int row = 0; row < SIZE_ROW; ++row)
    {
        swap(arr[row][original_col], arr[row][updated_col]);
        // int temp = arr[row][original_col];
        // arr[row][original_col] = arr[row][updated_col];
        // arr[row][updated_col] = temp;
    }
}

void swapRows(int arr[SIZE_ROW][SIZE_COL], int original_row, int updated_row)
{
    for(int col = 0; col < SIZE_COL; ++col)
    {
        swap(arr[original_row][col], arr[updated_row][col]);
        // int temp = arr[original_row][col];
        // arr[original_row][col] = arr[updated_row][col];
        // arr[updated_row][col] = temp;
    }

}

int main()
{
    int matrix[SIZE_ROW][SIZE_COL] = {{1, 2, 3},
                                      {4, 5, 6},
                                      {7, 8, 8}};
    int original_col = 0, updated_col = 2;
    int original_row = 0, updated_row = 2;

    cout << "Original Array: " << endl;
    printArray(matrix, SIZE_ROW, SIZE_COL);

    cout << "Modified Array after column swap: "<< endl;
    swapColumns(matrix, original_col, updated_col);
    printArray(matrix, SIZE_ROW, SIZE_COL);

    cout << "Modified Array after row swap: "<< endl;
    swapRows(matrix, original_row, updated_row);
    printArray(matrix, SIZE_ROW, SIZE_COL);

    return 0;
}
