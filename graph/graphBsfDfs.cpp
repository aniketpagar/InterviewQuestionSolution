#include<iostream> 
#include <list> 
#include "vector"
using namespace std; 

// This class represents a directed graph using 
// adjacency list representation 
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
	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints BFS traversal from a given source s 
	void BFS(int s); 
}; 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

//it works on queue
//breath first search
void Graph::BFS(int s) 
{ 
	// Mark all the vertices as not visited 
    vector<bool> visited(V, false);
	// Create a queue for BFS 
	list<int> queue; // here we can alos queue directly by adding the queue lib
	
	queue.push_front(s); 

	while(!queue.empty()) 
	{ 
		// Dequeue a vertex from queue and print it 
		int s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 
		//mark node as visited
		visited[s] = true; 

		// get all adjacent vertices of the dequeued 
		// vertex s. if a adjacent has not been visited, 
		// then mark it visited and enqueue it 
		for (auto i : adj[s]) 
		{ 
			if (!visited[i]) 
				queue.push_back(i); 
		} 
	} 
} 


int main() 
{ 

	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "BFS starting from vertex 2)  --> "; 
	g.BFS(2); 

	return 0; 
} 
