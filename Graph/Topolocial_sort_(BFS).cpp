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
	
	//bfs
	void bfs(int src){
		queue<int> q;

		//indegree
		int indegree[V] = {0};
		
		//update indegree by traversing x->y
		//indegree[y]++
		for(int x=src; x<V; x++){
			for(int y: l[x]){
				indegree[y]++;
			}
		}
		
		//bfs
		//1 . find nodes with 0 indegree
		for(int i=src; i<V; i++){
			if(indegree[i] == 0){
				q.push(i);
			}
		}
		
		while(!q.empty()){
			
			int cur = q.front();
			q.pop();
			
			cout<<cur<<" ";
			
			for(int nbr: l[cur]){
				indegree[nbr]--;
				if(indegree[nbr] == 0){
					q.push(nbr);
				}
				
			}
		}
		
	}
};
int main() {
	// your code goes here
	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(3, 5);
	
	g.bfs(0);
	
	return 0;
}