/*

Get positions of neighbours. (r, c) is the center position
and all other are its neighbours.

(r-1, c-1)        (r-1,c)       (r-1, c+1)
(r, c-1)          (r,c)         (r, c+1)
(r+1, c-1)        (r+1,c)       (r+1, c+1)

                {d, r, u, l}
int dirRow[4] = {1, 0, -1, 0}
int dirCol[4] = {0, 1, 0, -1}
*/



#include<bits/stdc++.h>
using namespace std;

#define SIZE_COL    5
#define SIZE_ROW    5

int main()
{
    int grades[SIZE_ROW][SIZE_COL] = {0}; // 5 * 5

    // direction arrays
    //               d, r, u, l, dl, dr, ul, ur
    // int dirRow[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    // int dirCol[8] = {0, 1, 0, -1, -1, 1, -1, 1};
    int dirRow[4] = {1, 0, -1, 0};
    int dirCol[4] = {0, 1, 0, -1};

    // stdin input
    for(int row = 0; row < SIZE_ROW; ++row)
        for(int col = 0; col < SIZE_COL; ++col)
            cin >> grades[row][col];

    //stdout output
    for(int row = 0; row < SIZE_ROW; ++row)
    {
        for(int col = 0; col < SIZE_COL; ++col)
            cout << grades[row][col] << " ";
        cout << endl;
    }

    int i = 2, j = 2;
    for(int d = 0; d < 4; ++d)
    {
        int neighbourI = i + dirRow[d];
        int neighbourJ = j + dirCol[d];

        cout << neighbourI << " " << neighbourJ << endl;
    }

    return 0;
}
