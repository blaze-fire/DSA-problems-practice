/*
Input:
12 16
1 3
1 9
9 12
11 9
11 12
3 5
5 7
7 3
5 1
3 6
6 1
6 2
2 8
3 8
2 4
4 10


Output:
1 : 0
2 : 1
3 : 0
4 : 4
5 : 0
6 : 0
7 : 1
8 : 1
9 : 1
10 : 5
11 : 1
12 : 1


*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	int *dp;
	public:
	Graph(int v){
		this->V = v;
		l = new list<int> [V];
		dp = new int [V];
	}
	
	void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	void dfs_helper(int src, int parent, bool visited[], int depth[], int dep){
		visited[src] = true;
		dp[src] = dep;
		depth[src] = dep;		//store depth of each node we visit
		
		for(int nbr: l[src]){
			if(!visited[nbr]){
				dfs_helper(nbr, src, visited, depth, dep+1);
				
				//min height i can reach from its subtrees or child nodes
				dp[src] = min(dp[src], dp[nbr]);
			}
			else if(nbr != parent){
				//if backedge leads to a lower level
				dp[src] = min(dp[src], depth[nbr]);
			}
		}
	}
	
	void dfs(int src){
		bool visited[V] = {false};
		int depth[V] = {0};
		
		for(int i=src; i<V; i++){
			if(!visited[i]){
				dfs_helper(i, -1, visited, depth, 0);
			}
		}
	}
	
	void print(int src){
		for(int i=src; i<V; i++){
			cout<<i<<" : "<<dp[i]<<endl;
		}
	}
	
};

int main() {

	int v, e;
	cin>>v>>e;
	
	Graph g(v+1);
	
	while(e--){
		int u, v;
		cin>>u>>v;
		g.addEdge(u, v);
	}
	
	g.dfs(1);
	g.print(1);
	return 0;
}