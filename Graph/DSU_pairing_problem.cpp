// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<pair<int, int>> l;
	
	public:
	Graph(int v){
		this->V = v;
	}
	
	void addEdge(int u, int v){
		l.push_back(make_pair(u, v));
	}
	
	int findSet(int i, int parent[]){
		if(parent[i] == -1){
			return i;
		}
		
		return parent[i] = findSet(parent[i], parent);
	}
	
	void union_set(int x, int y, int parent[], int rank[]){
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);
		
		if(s1 != s2){
			if(rank[s1] < rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
	
	void dsu(){
		int parent[V];
		int rank[V];
		
		for(int i=0; i<V; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
		
		for(pair<int, int> edge: l){
			int i = edge.first;
			int j = edge.second;
			
			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);
			
			if(s1 != s2){
				union_set(s1, s2, parent, rank);
			}
		}		
		
		vector<int> cities;
		int city = 0;
		
		for(int i=0; i<V; i++){
			if(rank[i] > 1 and parent[i] == -1){
				cities.push_back(rank[i]);
			}
			
			else if(rank[i] == 1 and parent[i] == -1){
				city++;
			}
		}
		
		
		int n = cities.size();
		int ans = 0;
		
		if(city != 0){
			for(int i=0; i<n; i++){
				ans += city*cities.at(i); 
			}
		}
		
		ans += (city*(city-1))/2;
		

		for(int i = 0; i<n; i++){
			for(int j=i+1; j<n; j++)
				ans += cities.at(i)*cities.at(j);
		}
		
	
		cout<<"Answer : "<<ans<<endl;
	}
	
};

int main() {
	// your code goes here
	int n, m;
	cin>>n>>m;
	Graph g(n);
	
	while(m--){
		int x, y;
		cin>>x>>y;
		g.addEdge(x, y);
	}
	
	g.dsu();
	return 0;
}
