#include "iostream"
using namespace std;
#include "vector"
#include "set"
#include "list"
#include "map"
int main()
{
   //vector stored in sequential manner in the memory
   vector<int>v1;
   v1.push_back(12);
   v1.push_back(2);
   v1.push_back(21);
   v1.push_back(1);
   cout<<"vector element: \n";
   for(auto it:v1) cout<<" "<<it;
   v1.pop_back();//delete from back
   v1.clear();//to delete all element of vector

  //set store data in ascending order(default)
  //set do not store duplicate data
  //
  //set<int,greater<int>>s1;//to stored in descending order
   set<int>s1;
   s1.insert(12);
   s1.insert(2);
   s1.insert(21);
   s1.insert(1);
   s1.insert(21);
   cout<<"\n set element: \n";
   for(auto it:s1) 
    cout<<" "<<it;
   s1.erase(2);//to delete 2 element from set
   s1.clear();//to delete all set element

   //list is same as a linklist
   //memory allocation is depend on availability of memory
   //list do not store sequentially
   //list are slower to access than vector
    list<int>l1;
   l1.push_back(12);
   l1.push_back(2);
   l1.push_back(21);
   l1.push_back(1);
   cout<<"\nlist element: \n";
   for(auto it:l1) 
    cout<<" "<<it;
   l1.pop_back();//delete from back
   l1.clear();//to delete all element of list


   //map is having key value pair
   //map do not store the duplicate key, instead map overwrite it
   cout<<"\n map element\n";
   map<int , int>m1;
   m1.insert({1,2});//store the element
   m1[9] = 3;//store the element in another way
   m1[1] = 3;// map will overwrite it as this key is already present

   for(auto it:m1) 
    cout<<" "<<it.second;
   m1.erase(1);//delete 1 key from the map
   m1.clear();//delete all the map


    // diff in map & multimap --> map dont store dublicate entry & multimap stored it
   cout<<"\n multi-map element\n";
   multimap<int,int>m2;
   m2.insert({1,2});//store the element
   m2.insert({1,12});
   m2.insert({1,99});// multi-map will store the duplicate key
   for(auto it:m2) 
    cout<<" "<<it.second;

   m2.erase(1);//it will delete all 1 key from the multimap;
   m2.clear();//clear all multimap element;
}