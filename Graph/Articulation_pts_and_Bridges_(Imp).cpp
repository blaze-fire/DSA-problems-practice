/*
 Input: 
5 5
1 2
2 3
3 1
3 4
4 5

Output:

1 : 1
2 : 1
3 : 1
4 : 4
5 : 5
Articulation pts : 4 3 

Edge from : 4, to : 5
Edge from : 3, to : 4


2nd Input
7 6
1 2
2 3
3 4
4 5
4 6
4 7


Output:
1 : 1
2 : 2
3 : 3
4 : 4
5 : 5
6 : 5
7 : 5
Articulation pts : 2 3 4 

Edge from : 4, to : 5
Edge from : 4, to : 6
Edge from : 4, to : 7
Edge from : 3, to : 4
Edge from : 2, to : 3
Edge from : 1, to : 2

 */
#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	set<int> articulation_pts;		//can also use set to avoid multiple entries
	vector<pair<int, int>> bridges;
	public:
	Graph(int v){
		this->V = v;
		l = new list<int> [V];
	}
	
	void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	void dfs_helper(int src, int parent, int low[], int discovery[], int timer){
		discovery[src] = ++timer;
		low[src] = timer;
		int num_child = 0;
		
		for(int nbr: l[src]){
			if(!discovery[nbr]){
				dfs_helper(nbr, src, low, discovery, timer);
		
				low[src] = min(low[src], low[nbr]);
				
				num_child++;
				
				//articulation pt
				if(parent != -1 and low[nbr] >= discovery[src]){
					articulation_pts.insert(src);
				}
				
				//bridge
				if(low[nbr] > discovery[src]){
					bridges.push_back({src, nbr});
				}
				
			}
			else if(nbr != parent){
				//minimum of current node or where the backedge is pointing to
				//discovery[nbr] : shows where backedge is pointing to
				low[src] = min(discovery[nbr], low[src]);
			}
		}
		
		//seperate case for root node (if root is a articulation pt.)
		if(parent == 0 and num_child >= 2){
			articulation_pts.insert(src);
		}
	}
	
	void dfs(int src){
		int low[V] = {0};
		int discovery[V] = {0};
		
		for(int i=src; i<V; i++){
			if(!discovery[i]){
				dfs_helper(i, -1, low, discovery, 0);
			}
		}
		
		for(int i=src; i<V; i++){
			cout<<i<<" : "<<low[i]<<endl;
		}
		
		cout<<"Articulation pts : ";
		for(int pt: articulation_pts){
			cout<<pt<<" ";
		}
		
		cout<<endl<<endl;
		
		for(int i=0; i<bridges.size(); i++){
			pair<int, int> p = bridges.at(i);
			cout<<"Edge from : "<<p.first<<", to : "<<p.second<<endl;
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
	return 0;
}