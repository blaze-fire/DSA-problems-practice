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
	
	bool dfs_helper(int src, int dist[], int &temp){
		for(int nbr: l[src]){
			if(dist[nbr] == -1){
				dist[nbr] = dist[src] + 1;
				bool subprob = dfs_helper(nbr, dist, temp);	
				if(subprob)
					return subprob;
			}
			
			else if(dist[nbr] >= dist[src]){
				temp = min(temp, dist[nbr] + dist[src] + 1);
				return true;
			}
		}
		
		return false;
	}
	
	int shortestCycle(){
		
		int dist[V] = {0};
		int shortestCycle = INT_MAX; 
		for(int i=0; i<V; i++){
			if(dist[i] == 0){
				int temp = INT_MAX;
				dist[i] = 1;
				bool isCycle = dfs_helper(i, dist, temp);
				if(isCycle){
					shortestCycle = min(shortestCycle, temp);
				}
			}		
		}
		
		return shortestCycle;
	}
};
int main() {
	// your code goes here
	Graph g(6);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(5, 3);
	
	cout<<g.shortestCycle();
	
	return 0;
}