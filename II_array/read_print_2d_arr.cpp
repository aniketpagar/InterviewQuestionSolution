/****************************************************************************
File name: read_print_2d_arr.cpp

Author: babajr
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;

#define SIZE_COL    5
#define SIZE_ROW    5

int main()
{
    int grades[SIZE_ROW][SIZE_COL] = {0}; // 5 * 5
    int avg = 0, sum = 0;

    // stdin input
    for(int row = 0; row < SIZE_ROW; ++row)
        for(int col = 0; col < SIZE_COL; ++col)
            cin >> grades[row][col];

    //stdout output
    /*
    for(int row = 0; row < SIZE_ROW; ++row)
    {
        double sum = 0;
        for(int col = 0; col < SIZE_COL; ++col)
            sum += grades[row][col];

        avg = sum / SIZE_ROW;
        cout << "Student # " << row + 1 <<
        " has average grade: " << avg << "\n";
    }
    */

    // Flattening of 2D array i.e. converting 2D array into 1D array.
    int idx = 0;
    for(int i = 0; i < SIZE_ROW; ++i)
    {
        for(int j = 0; j < SIZE_COL; ++j)
        {
            cout << "Index " << idx << " has r, c = " <<
            i << " " << j << endl;
            ++idx;
        }
    }

    return 0;
}
