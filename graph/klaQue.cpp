/*
Example
n = 10 nodes
Edges = [[1,2], [1,3], [2,4], [3,5], [7,8]]

There are two isolated sets with more than one node, {1,2,3,4,5} and {7,8}. The ceilings of their square roots 
are 5 ^ 1/2 = 2.236 and ceil(2.236) = 3, 2 ^ 1/2 = 1.414 and ceil (1.414) = 2. The other three isolated nodes 
are separate and the square root of their weights is 1 ^ 1/2 = 1 respectively. The sum is 3 + 2 + (3 * 1) = 8.

Input has two parameters:
n - no of nodes
edges - list of edges, each edge is represented a string "1 2"

output:
int: an integer that denotes the sum of the values calculated.
*/

#include<vector>
#include<queue>
#include<utility>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void input(vector<pair<int,int>> &v, int n) {
	for (int i = 0 ; i < n ; i++) {
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
}

void dfs(int node, int &sum, vector<vector<int> > &g, vector<int> &vis) {
	vis[node] = 1;
    cout<<" i am in dfs"<<endl;
	++sum;

	for (auto x : g[node]) {
		if (vis[x] == 0)
			dfs(x,sum,g,vis);
	}
}


int main() {
	int n=10;// lets consider the 10 node
	//cin >> n;
	
	vector<pair<int,int> > v = {{1,2},{1,3},{2,4},{3,5},{7,8}};
	
	vector<int> vis(n+1,0);
	vector<vector<int> > g(n+1);

	for (auto x : v) {
		g[x.first].push_back(x.second);
		g[x.second].push_back(x.first);
	}


	int total_sum = 0;

	for (int i = 1 ; i <= n ; i++) {
		int sum = 0;
		if (vis[i] == 0) {
			dfs(i,sum,g,vis);
			cout << "sum " << sum << "\n";
			total_sum += ceil(sqrt(sum));
		}
	}

	cout << "Total Sum " << total_sum;
}
