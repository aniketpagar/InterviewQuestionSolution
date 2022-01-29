/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
  -   -
|   |   |
  -   -
|   |   |
  -   -
|   |   |
  -   -
*/
#include <bits/stdc++.h>
using namespace std;

#define ROW_SIZE     3
#define COL_SIZE     2


/*
Brute Force: Using Recursion.
Try for all the possible paths from start to end.
TC = Exponential, SC = Exponential
*/
int count_paths(int arr[][COL_SIZE], int r_idx, int c_idx)
{
    // base cases
    if(r_idx == (ROW_SIZE - 1) || c_idx == (COL_SIZE - 1))
        return 1;

    if(r_idx >= ROW_SIZE || c_idx >= COL_SIZE)
        return 0;

    return count_paths(arr, r_idx + 1, c_idx) + count_paths(arr, r_idx, c_idx + 1);
}


int count_paths_bf(int arr[][COL_SIZE], int r_idx, int c_idx)
{
    // base cases
    if(r_idx == 1 || c_idx == 1)
        return 1;

    return count_paths_bf(arr, r_idx - 1, c_idx) + count_paths_bf(arr, r_idx, c_idx - 1);
}

/*
Better Approach: Using Recursion + Dynammic Programming.
Try for all the possible paths from start to end. store the already found values
for r_idx, c_idx in dp table.
TC = O(n2), SC = O(n2)
*/
int count_paths_dp(int arr[][COL_SIZE], int r_idx, int c_idx, int dp[][COL_SIZE])
{
    // base cases
    if(r_idx == (ROW_SIZE - 1) || c_idx == (COL_SIZE - 1))
        return 1;

    if(r_idx >= ROW_SIZE || c_idx >= COL_SIZE)
        return 0;

    // first check for (r_idx, j_idx), value is already found
    if(dp[r_idx][c_idx] != -1)
        return dp[r_idx][c_idx];

    return count_paths_dp(arr, r_idx + 1, c_idx, dp) + count_paths_dp(arr, r_idx, c_idx + 1, dp);
}


/*
Optimal Approach: Observing the pattern and using the nCr approach.

Ex: 3 * 2 Matrix
  -   -
|   |   |
  -   -
|   |   |
  -   -
|   |   |
  -   -
R = right, D = Down
Total number of directions = (RDD) + (DDR) + (DRD) = 3
(num_of_directions)

General Formula ==> num_of_directions = (r_size - 1) + (c_size - 1)
                                      = r_size + c_size - 2

Number of paths => num_of_paths (3 * 2) = 3C2 ((num_of_directions) C (r_size - 1))
                                          or
                                        = 3C1 ((num_of_directions) C (c_size - 1))
TC = O(n), SC = O(1)
*/
int count_paths_optimised(int arr[][COL_SIZE], int r_idx, int c_idx)
{
    int num_of_directions = (ROW_SIZE + COL_SIZE - 2);
    int r_size = (ROW_SIZE - 1);
    double res = 1;

    // calculating nCr ==> eg 10C3 = 8*9*10/1*2*3
    // loop is for getting denominator values as well as numerator values.
    for(int i = 1; i <= r_size; i++)
        res = res * (num_of_directions - r_size + i) / i;

    return (int)res;
}


int main(void)
{
    int arr[][COL_SIZE] = {{1,2},
                   {3,4},
                   {5,6}};
    int dp[][COL_SIZE] = {{-1,-1},
                   {-1,-1},
                   {-1,-1}};

    printf("Number of Paths: %d\n", count_paths(arr, 0, 0)); // starting from 0,0
    printf("Number of Paths: %d\n", count_paths_bf(arr, ROW_SIZE, COL_SIZE));// starting from 3,2
    printf("Number of Paths: %d\n", count_paths_dp(arr, 0, 0, dp));
    printf("Number of Paths: %d\n", count_paths_optimised(arr, 0, 0));

    return 0;
}
