
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    // int n = 10;
    int n;
    int res, res1, res2, res3;
    int pos;

    cout << "Enter the decimal number:" << endl;
    cin >> n;

    cout << "Enter the position: " << endl;
    cin >> pos;

    //setting bit
    res = n | (1 << pos);
    printf("Set bit:%d\n", res); // 1010    =>  1110

    //clearing bit 1010
    res1 = n & ~(1 << pos);
    printf("Result after clearing bit:%d\n", res1);//1110 => 1010

    //checking bit
    res2 = n & (1 << pos);
    printf("Checking bit:%d\n", res2); //False

    //toggling bit
    res3 = n ^ (1 << pos);
    printf("Result after toggling bit:%d\n", res3);//1110
    return 0;
}
