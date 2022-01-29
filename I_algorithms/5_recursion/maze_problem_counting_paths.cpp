/****************************************************************************
File name: maze_problem_counting_paths.cpp

Author: babajr
*****************************************************************************/


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
#define COL_SIZE     3


/*
API to count the number of paths from grid point (0,0) to (ROW, COL).
Allowed Directions: Down (Vertical), Right (Horizontal)
*/
int count_paths(int r_size, int c_size)
{
    if(r_size == 1 || c_size == 1)
        return 1;

    return (count_paths(r_size - 1, c_size) + count_paths(r_size, c_size - 1));
}


/*
API to print the paths from the start to end of the matrix/maze.
Allowed Directions: Down (Vertical), Right (Horizontal)
*/
void print_paths(string path, int r_size, int c_size)
{
    if(r_size == 1 && c_size == 1)
    {
        cout << path << endl;
        return;
    }

    if(r_size > 1)
        print_paths(path + "D", r_size - 1, c_size);

    if(c_size > 1)
        print_paths(path + "R", r_size, c_size - 1);
}


/*
API to print the paths from start to end of maze.
Allowed Directions: Down (Vertical), Right (Horizontal) & Diagonal
*/
void print_paths_diagonal(string path, int r_size, int c_size)
{
    if(r_size == 1 && c_size == 1)
    {
        cout << path << endl;
        return;
    }


    if(r_size > 1 && c_size > 1) // diagonal
        print_paths(path + "D", r_size - 1, c_size - 1);

    if(r_size > 1) // down
        print_paths(path + "V", r_size - 1, c_size);

    if(c_size > 1) // right
        print_paths(path + "H", r_size, c_size - 1);
}


/*
API to print the paths with some restrictions.
*/
void print_paths_with_restrictions(bool maze[][COL_SIZE], string path, int r, int c)
{
    if(r == ROW_SIZE - 1 && c == COL_SIZE - 1)
    {
        cout << path << endl;
        return;
    }

    if(maze[r][c] == false)
        return;

    if(r < ROW_SIZE - 1)
        print_paths_with_restrictions(maze, path + "D", r + 1, c);

    if(c < COL_SIZE - 1)
        print_paths_with_restrictions(maze, path + "R", r, c + 1);
}


int main(void)
{
    // printf("Number of paths: %d\n", count_paths(ROW_SIZE, COL_SIZE));
    // print_paths("", ROW_SIZE, COL_SIZE);
    // print_paths_diagonal("", ROW_SIZE, COL_SIZE);

    // count paths with some restrictions.
    // false ==> you can not go to that cell
    bool maze[ROW_SIZE][COL_SIZE] = {
                        {true, true, true},
                        {true, false, true},
                        {true, true, true}
                    };


    print_paths_with_restrictions(maze, "", 0, 0);

    return 0;
}
