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
		//l[v].push_back(u);
	}
	
	void dfs_helper(int src, bool visited[], list<int> &ordering){
		visited[src] = true;

		for(int nbr: l[src]){
			if(!visited[nbr]){
				dfs_helper(nbr, visited, ordering);	
			}
		}
		
		//at this point
		ordering.push_front(src);
		return;
	}
	
	void dfs(int src){
		
		bool visited[V] = {false};
		list<int> ordering;
		
		for(int i=src; i<V; i++){
		
			if(!visited[i]){
				dfs_helper(i, visited, ordering);
			}		
		
		}
		
		//finally print the list
		for(int node: ordering){
			cout<<node<<" ";
		} 		
	}
};
int main() {
	Graph g(5);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	
	g.dfs(1);
	
	return 0;
}