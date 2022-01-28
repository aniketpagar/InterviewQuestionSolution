/*
Program to allocate memory dynamically to 2D array and store the strings as a row in
that array.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define COL_SIZE    10
#define ROW_SIZE    3


/*
Helper API to read the strings.
*/
void read_string(char c[])
{
    int i = 0;

    while(i < COL_SIZE)
    {
        c[i] = getchar();

        if(c[i] == '\n')
            break;

        i++;
    }

    c[++i] = '\0';
}


/*
Helper API to get the data from the user through command line.
*/
// void get_data_user(char c[][COL_SIZE])
void get_data_user(char **c)
{
    for(int i = 0; i < ROW_SIZE; i++)
    {
        printf("Enter String: ");
        read_string(c[i]);
    }
}


/*
Helper API to print the data of 2D array.
*/
// void print_data(char c[][COL_SIZE])
void print_data(char **c)
{
    for(int i = 0; i < ROW_SIZE; i++)
        printf("%s", c[i]);
        // printf("%s\n", c[i]);

}

/*
Create 3 * 10 2D array. COL_SIZE = 10, ROW_SIZE = 3
*/
int main(void)
{
    char **c = NULL;

    c = (char **)malloc(sizeof(char) * ROW_SIZE);

    // c[0] = (char *)malloc(sizeof(char) * COL_SIZE);
    // c[1] = (char *)malloc(sizeof(char) * COL_SIZE);
    // c[2] = (char *)malloc(sizeof(char) * COL_SIZE);

    for(int i = 0; i < ROW_SIZE; i++)
    {
        c[i] = (char *)malloc(sizeof(char) * COL_SIZE);
    }

    // specifying intput directly
    // strncpy(c[0], "hello", sizeof("hello"));
    // strncpy(c[1], "hello", sizeof("hello"));
    // strncpy(c[2], "hello", sizeof("hello"));

    // get the input directly from the ser.
    get_data_user(c);
    print_data(c);

    return 0;
}

