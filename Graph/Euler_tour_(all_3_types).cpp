#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	int *tin, *tout;
	int timer=0;
	public:
	Graph(int v){
		this->V = v;
		l = new list<int> [V];
		tin = new int [V];
		tout = new int [V];
	}
	
	void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	void euler_tour_1(int src, int parent){
		cout<<src<<" ";		
		tin[src] = ++timer;
		
		for(int nbr: l[src]){
			if(nbr != parent){
				euler_tour_1(nbr, src);
				cout<<src<<" ";
				tout[src] = ++timer;
			}
		}
		
		return;
	}
	
	void euler_tour_2(int src, int parent){
		cout<<src<<" ";
		tin[src] = ++timer;
		
		for(int nbr: l[src]){
			if(nbr != parent){
				euler_tour_2(nbr, src);
			}
		}
		cout<<src<<" ";
		tout[src] = ++timer;
		return;
	}
	
	void euler_tour_3(int src, int parent){
		cout<<src<<" ";
		tin[src] = ++timer;
		for(int nbr: l[src]){
			if(nbr != parent){
				euler_tour_3(nbr, src);
			}
		}
		tout[src] = timer;
		return;
	}
	
	//whether x is ancestor of y or not
	bool isAncestor(int x, int y){
		if(tin[x] <= tin[y] and tout[x] >= tout[y]){
			return true;
		}
		
		return false;
	}
	
	void print(){
		cout<<endl<<endl;
		for(int i=1; i<V; i++){
			cout<<"For node : "<<i<<", tin: "<<tin[i]<<", tout : "<<tout[i];
			cout<<endl;
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
	
	g.euler_tour_3(1, 0);
	g.print();
	cout<<g.isAncestor(7, 1);
	return 0;
}