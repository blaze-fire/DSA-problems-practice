// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Graph{
	ll V;
	list<pair<ll, ll>> *l;
	
	public:
	Graph(ll v){
		V = v;
		l = new list<pair<ll, ll>> [V];
	}
	
	void addEdge(ll u, ll v, ll w){
		l[u].push_back(make_pair(v, w));
		l[v].push_back(make_pair(u, w));
	}

	ll dfs_helper(ll src, bool visited[], ll count[], ll &ans){
		visited[src] = true;
		count[src] = 1;
		
		for(pair<ll, ll> nbr: l[src]){
			if(!visited[nbr.first]){
				count[src] += dfs_helper(nbr.first, visited, count, ans);
				ans += min(count[nbr.first], V- 1 -count[nbr.first])*2*nbr.second;
			}
		}
		
		return count[src];
	}
	
	ll dfs(){
		bool visited[V] = {false};
		ll count[V] = {0};

		ll ans=0;
		
		dfs_helper(1, visited, count, ans);
		return ans;
	}
	
};



int main() {
	// your code goes here
	int tc;
	cin>>tc;
	
	for(int i=1; i<=tc; i++){
		ll n;
		cin>>n;
		Graph g(n+1); 
		
		for(ll i=0; i<n-1; i++){
			ll u, v, w;
			cin>>u>>v>>w;
			g.addEdge(u, v, w);
		}
		cout<<"Case #"<<i<<": "<<g.dfs()<<endl;
	}
	return 0;
}