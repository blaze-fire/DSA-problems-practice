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
	
	bool dfs_helper(int src, bool visited[], bool stack[]){
		//when visiting a node mark visited and also include in current path in stack 
		visited[src] = true;
		stack[src] = true;
		
		for(int nbr: l[src]){
			//two cases
			
			//if in current path
			if(stack[nbr] == true){
				return true;
			}
			
			else if(!visited[nbr]){
				if(dfs_helper(nbr, visited, stack))
					return true;
			}
			
			
		}
		
		//remove from current path after all neighboring nodes visted fron current node
		stack[src] = false;
		return false;
	}
	
	void dfs(int src){
		
		bool visited[V] = {false};
		bool  stack[V] = {false};
		
		for(int i=src; i<V; i++){
		
			if(!visited[i]){
				bool isCycle = dfs_helper(i, visited, stack);
				if(isCycle){
					cout<<"Contains cycle"<<endl;
					return;
				}
			}		
		
		}
		cout<<"No cycle"<<endl;
	}
};
int main() {
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 5);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 2);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	
	g.dfs(0);
	
	return 0;
}