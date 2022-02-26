#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *graph;
	list<int> *rev_graph;		//reverse_graph
	
	public:
	Graph(int v){
		V = v;
		graph = new list<int> [V];
		rev_graph = new list<int> [V];
	}
	
	void addEdge(int u, int v){
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}
	
	void dfs_helper(int src, bool visited[], vector<int> &stack){
		//when visiting a node mark visited  
		visited[src] = true;
		
		for(int nbr: graph[src]){
			if(!visited[nbr]){
				dfs_helper(nbr, visited, stack);	
			}
			
		}
		
		//node finished last will be pushed in the stack
		stack.push_back(src);
	}
	
	
	//dfs function for reverse_graph
	void dfs_helper_reverse(int src, bool visited[]){
		
		//when visiting a node mark visited  
		visited[src] = true;
		cout<<src<<" ";
		
		for(int nbr: rev_graph[src]){
			if(!visited[nbr]){
				dfs_helper_reverse(nbr, visited);	
			}
			
		}
		
	}
	
	
	
	void dfs(int src){
		
		bool visited[V] = {false};
		vector<int> stack;
		
		//Step 1: store nodes according to dfs finish time		
		for(int i=src; i<V; i++){
			if(!visited[i]){
				dfs_helper(i, visited, stack);
			}		
		}
		
		// ordering = stack
		//Step 2: reverse the graph (already done);

		//step 3: do dfs according to vertices given the stack on reverse_graph
		bool visited_reverse_graph[V] = {false};
		char component = 'A';
		for(int x=stack.size()-1; x>= 0; x--){
			int node = stack[x];
			
			if(!visited_reverse_graph[node]){
				//there is a component starting from this node
				cout<<"component : "<<component<<" -- ";
				dfs_helper_reverse(node, visited_reverse_graph);
				cout<<endl;
				component++;
			}
		}
	}
};
int main() {
	Graph g(7);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 5);
	g.addEdge(6, 3);
	g.addEdge(3, 4);
	g.addEdge(5, 6);
	
	g.dfs(0);
	
	return 0;
}