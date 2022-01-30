/****************************************************************************
File name: get_max_value_last_occurance_2d_arr.cpp

Author: babajr
*****************************************************************************/


/*
Find the position of maximum element in a given matrix.
If multiple maximum values are present, find the last occurance.

Input: {{1,5,1,10}, {2,10,3,4}, {1,10,10,7}} and value = 10
Ouput: 2 2

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

/* Approach 1: Brute Force.
   TC = O(n2)
*/

void findPositionMaxvalue(int arr[SIZE_ROW][SIZE_COL], int rowSize, int colSize)
{
    int maxRowIdx = 0;
    int maxColIdx = 0;

    for(int i = 0; i < rowSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            if(arr[i][j] >= arr[maxRowIdx][maxColIdx]) // >= --> to get last occurance. > --> used to get first occurance.
            {
                maxRowIdx = i;
                maxColIdx = j;
            }
        }
    }

    cout << "Max Value at position " << maxRowIdx << " " <<
    maxColIdx << " with value = " << arr[maxRowIdx][maxColIdx];
}


void printSum(int arr[SIZE_ROW][SIZE_COL], int rowSize, int colSize)
{
    int sumLeftD = 0, sumRightD = 0, sumLastRow = 0, sumLastCol = 0;

    // To get left diagonal sum.
    //  1   2   3
    //  4   5   6
    //  7   8   9
    // left diagonal sum = 1 + 5 + 9
    int i = 0, j = 0;
    while(i < rowSize && j < colSize)
        sumLeftD += arr[i++][j++];

    // To get right diagonal sum.
    // right diagonal sum = 3 + 5 + 7
    i = 0, j = colSize - 1;
    while(i < rowSize && j >= 0)
        sumRightD += arr[i++][j--];

    // To get the last row sum.
    j = 0;
    while(j < colSize)
        sumLastRow += arr[rowSize - 1][j++];

    // To get the last column sum.
    i = 0;
    while(i < rowSize)
        sumLastCol += arr[i++][colSize - 1];

    cout << "Left Diagonal Sum: " << sumLeftD << endl;
    cout << "Right Diagonal Sum: " << sumRightD << endl;
    cout << "Last Row Sum: " << sumLastRow << endl;
    cout << "Last Column Sum: " << sumLastCol << endl;
}


int main()
{
    int matrix[SIZE_ROW][SIZE_COL] = {{1, 2, 3},
                                      {4, 5, 6},
                                      {7, 8, 8}};

    printArray(matrix, SIZE_ROW, SIZE_COL);

    // findPositionMaxvalue(matrix, SIZE_ROW, SIZE_COL);
    printSum(matrix, SIZE_ROW, SIZE_COL);
    return 0;
}
