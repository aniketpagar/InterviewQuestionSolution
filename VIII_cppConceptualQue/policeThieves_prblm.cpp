/*
Policemen catch thieves
Difficulty Level : Medium
Given an array of size n that has the following specifications: 

Each element in the array contains either a policeman or a thief.
Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from the policeman.
We need to find the maximum number of thieves that can be caught.
Examples: 
 

Input : arr[] = {'P', 'T', 'T', 'P', 'T'},
            k = 1.
Output : 2.
Here maximum 2 thieves can be caught, first
policeman catches first thief and second police-
man can catch either second or third thief.

Input : arr[] = {'T', 'T', 'P', 'P', 'T', 'P'}, 
            k = 2.
Output : 3.

Input : arr[] = {'P', 'T', 'P', 'T', 'T', 'P'},
            k = 3.
Output : 3

*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using namespace std;


int NumOfThieveCatchByPolice(char arr[], int n, int k)
{
	int ans=0;
    vector<bool>dp(n,false);
    int min(0),max(0);
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='P')//check which thieve this police can catch
        {
            i-k<0?min=0:min=i-k;
            i+k>n?max=n-1:max=i+k;
            //cout<<"min : "<<min<<" max:"<<max<<endl;
            for(int j =min;j<=max;j++)
            {
                //cout<<"j : "<<j<<endl;
                if(arr[j]=='T'&& dp[j]==false)// if thieve not catched.
                {
                    //cout<<"j : "<<j<<endl;
                    dp[j]= true;//thieve catch by police
                    ans++;
                    j=max+1;//to break this for loop
                }
            }
        }
    }
    return ans;    
}

// Driver program
int main()
{
	int k, n;

	char arr1[] = { 'P', 'T', 'T', 'P', 'T' };
	k = 2;
	n = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Maximum thieves caught: "
		<< NumOfThieveCatchByPolice(arr1, n, k) << endl;

	char arr2[] = { 'T', 'T', 'P', 'P', 'T', 'P' };
	k = 2;
	n = sizeof(arr2) / sizeof(arr2[0]);
	cout << "Maximum thieves caught: "
		<< NumOfThieveCatchByPolice(arr2, n, k) << endl;

	char arr3[] = { 'P', 'T', 'P', 'T', 'T', 'P' };
	k = 3;
	n = sizeof(arr3) / sizeof(arr3[0]);
	cout << "Maximum thieves caught: "
		<< NumOfThieveCatchByPolice(arr3, n, k) << endl;

	return 0;
}
