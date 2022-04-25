#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector<vector<int>> vec = { { 1, 2, 3, 4, 5 }, 
    //                             { 16, 17, 18, 19, 6 },
    //                             { 15, 24, 25, 20, 7 },
    //                             { 14, 23, 22, 21, 8}, 
    //                             { 13, 12, 11, 10, 9 }
    //                           };
    vector<vector<int>> vec = { { 1}, 
                                {2},
                                {3},
                                {4}, 
                                {5} 
                              };

    // The boundaries for the current iteration
    int top = 0, bottom = vec.size() - 1, left = 0, right = vec[0].size() - 1;

    while (top <= bottom && left <= right) {

        // Print Top Row of the matrix
        for(int i = left; i <= right; i++) {
            cout << vec[top][i] << " ";
        }
        top++;

        if(!(top <= bottom && left <= right))
         break;

        // Print right side 
        for(int i = top; i <= bottom; i++) {
            cout << vec[i][right] << " ";
        }
        right--;

        if(!(top <= bottom && left <= right))
         break;

        // Print Bottom Row
        for(int i = right; i >= left; i--) {
            cout << vec[bottom][i] << " ";
        }

        bottom--;
        if(!(top <= bottom && left <= right))
         break;

        // Print left row
        for(int i = bottom; i >= top; i--) {
            cout << vec[i][left] << " ";
        }
        left++;
    }

    cout << "\n";
}