/****************************************************************************
File name: greedy_robot.cpp

Author: babajr
*****************************************************************************/


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
   TC = O(n)
*/
/*
void greedyRobot(int arr[SIZE_ROW][SIZE_COL])
{
    int sum = 0, row = 0, col = 0;

    while(row < SIZE_ROW && col < SIZE_COL)
    {
        sum += arr[row][col];

        int next_val = 0, best_row = -1, best_col = -1;

        // is right OK position
        if(col + 1 < SIZE_COL)
        {
            next_val = arr[row][col + 1];
            best_row = row;
            best_col = col + 1;
        }

        // is down OK position
        if(row + 1 < SIZE_ROW)
        {
            if(best_row == -1 || (next_val < arr[row + 1][col]))
            {
                next_val = arr[row + 1][col];
                best_row = row + 1;
                best_col = col;
            }
        }

        // is diagonal OK position
        if((row + 1 < SIZE_ROW) && (col + 1 < SIZE_COL))
        {
            if(best_row == -1 || (next_val < arr[row + 1][col + 1]))
            {
                next_val = arr[row + 1][col + 1];
                best_row = row + 1;
                best_col = col + 1;
            }
        }

        if(best_row == -1)
            break;

        row = best_row;
        col = best_col;
    }

    cout << sum << endl;
}
*/

/*
Approach 2: Use direction array.

In approach 1, we tried 3 positions
--> (row + 1, col), (row, col + 1), (row + 1, col + 1)
The shift from (row, col) is
--> (1,     0),     (0,     1),     (1,         1)

We can code this shifts in two arrays i.e. direction arrays.
dRow[3] = {1, 0, 1}
dCol[3] = {0, 1, 1}

Use direction arrays whenever you want to move to neighbours.
*/
void greedyRobot(int arr[SIZE_ROW][SIZE_COL])
{
    int sum = 0, row = 0, col = 0;
    // Direction arrays to move to neighbours.
    int dRow[3] = {1, 0, 1};
    int dCol[3] = {0, 1, 1};

    while(row < SIZE_ROW && col < SIZE_COL)
    {
        sum += arr[row][col];

        int next_val = 0, best_row = -1, best_col = -1;

        for(int d = 0; d < 3; ++d)
        {
            int newRow = row + dRow[d];
            int newCol = col + dCol[d];

            if(newRow < SIZE_ROW && newCol < SIZE_COL)
            {
                if(best_row == -1 || next_val < arr[newRow][newCol])
                {
                    next_val = arr[newRow][newCol];
                    best_row = newRow;
                    best_col = newCol;
                }
            }
        }

        if(best_row == -1)
            break;

        row = best_row;
        col = best_col;
    }

    cout << sum << endl;
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

    greedyRobot(matrix);

    return 0;
}
