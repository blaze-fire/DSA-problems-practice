// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	
	public:
	Graph(int v){
		V = v;
		l = new list<int> [V];
	}
	
	void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void dfs_helper(int src, bool visited[]){
		visited[src] = true;
		
		cout<<src<<endl;
		for(int nbr: l[src]){
			if(!visited[nbr])
				dfs_helper(nbr, visited);
		}
	}
	
	void dfs(int src){
		bool visited[V] = {false};
		
		dfs_helper(src, visited);
	}
	
};



int main() {
	// your code goes here
	Graph g(7);
	
	g.addEdge(0,1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);

	g.dfs(0);
	return 0;
}