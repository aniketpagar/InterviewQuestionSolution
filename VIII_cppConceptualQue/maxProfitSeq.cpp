// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;
#include "vector"
 
// A structure to represent a job
struct Job
{
   char id;     // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};
 

void printJobScheduling(Job arr[], int n)
{
    //sort as per the profit
    Job temp;
    for(int i =0; i <n ;i++)
    for(int j =0;j<n;j++)
    {
        if(arr[i].profit>arr[j].profit)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //display the sorted profit list
    cout << "sorted(per profit) job"<<endl;
    for(int i =0;i<n;i++)
        cout<<" "<<arr[i].profit<<" "<<arr[i].id<<" "<<arr[i].dead<<endl;
    
    vector<char> ans;
    int t =1;
    //algorithm
    for(int i =0;i<n;i++)
    {
        if(arr[i].dead >= t){
            ans.push_back(arr[i].id);
            t++;
        }
        
    }
    cout << "Following is maximum profit sequence of jobs \n";
        for(auto it:ans)
            cout<<" "<<it;
}
 
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
      
    printJobScheduling(arr, n);
    return 0;
}