// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	int *parent, *depth;
	public:
	Graph(int v){
		this->V = v;
		l = new list<int> [V];
		parent = new int [V];
		depth = new int [V];
		
		for(int i=0; i<V; i++){
			parent[i] = depth[i] = 0;
		}
	}
	
	void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	void dfs_helper(int src, int par){
		parent[src] = par;
		for(int nbr: l[src]){
			if(nbr != par){
				depth[nbr] = depth[src] + 1;
				dfs_helper(nbr, src);
			}
		}
		return;
	}
	
	void dfs(int src, int par){
		dfs_helper(src, par);
	}
	
	int lca_brute(int u, int v){
		if(u == v)	return u;
		
		//always assume u to be at deeper level always
		if(depth[u] < depth[v])	swap(u, v);
		//now u will always be at greater depth
		
		//bring both at same level
		while(depth[u] != depth[v]){
			u = parent[u];
		}
		
		//now move both of them together
		while(u != v){
			u = parent[u];
			v = parent[v];
		}
		
		return u;
	}
	
};

int main() {
	// your code goes here
	int v, e;
	cin>>v>>e;
	Graph g(v+1);
	
	for(int i =0; i<e; i++){
		int x, y;
		cin>>x>>y;
		
		g.addEdge(x, y);
	}
	g.dfs(1, 0);
	
	cout<<g.lca_brute(9, 2);
	
	return 0;
}