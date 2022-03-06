#include<iostream> 
#include <list> 
#include "vector"
using namespace std; 
#include <map>

//to check cycle in directed graph
//check the below link for cycle understanding
//https://www.youtube.com/watch?v=0dJmTuMrUZM

class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency 
	// lists 
	list<int> *adj; 
   
public: 
	Graph(int V) 
	{ 
	   this->V = V; 
	   adj = new list<int>[V]; 
   } 

	void addEdge(int v, int w); 
    bool isCycle(int v);
    bool cycle_util(int n,vector<bool>visisted);

}; 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

bool Graph::cycle_util(int v, vector<bool>visited)
{
    //cout<<v<<endl;
    if(visited[v]==true)
        return true;//having cycle
    visited[v]=true;
    for(auto it:adj[v])
    {
        if(cycle_util(it,visited)==true)
            return true;
    }
    return false;
}

bool Graph::isCycle(int v)
{
    vector<bool>visited(v,false);
    for(int i=0; i <v;i++)// we need to start from each node, pls check the video https://www.youtube.com/watch?v=0dJmTuMrUZM for more info
    {
        visited[i]=true;
        for(auto it:adj[i])//this is traversing the adjacent list
        {
            if(cycle_util(it,visited))
              return true;//having cycle
        }
        visited[i]=false;
    }
    return false;
}

int main() 
{ 

	Graph g(5); //argument is the number of vertices

    g.addEdge(0, 1); 
	g.addEdge(2, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 4); 
    g.addEdge(4, 0); 
   // g.addEdge(4, 2); //uncomment this to make cycle

	if(g.isCycle(5))//argument is the number of vertices
      cout<<" graph is having cycle";
    else
      cout<<" graph is not having cycle";

	return 0; 
} 
