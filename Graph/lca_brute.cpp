#include<bits/stdc++.h>

/*
 * Input:
19 18
1 2
2 4
2 5
5 6
6 7
6 8
6 9
1 3
3 10
3 11
10 17
11 12
17 18
17 19
12 13
12 14
12 15
15 16

Output: 1
Output: 3

 * */

using namespace std;

class Graph{
    int V;
    list<int> *l;
    int *par, *depth;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        par = new int [V];
        depth = new int [V];

        for(int i=0; i<V; i++){
            par[i] = 0;
            depth[i] = -1;
        }
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs_helper(int src, int parent){
        par[src] = parent;

        for(int nbr: l[src]){
            if(depth[nbr] == -1){
                depth[nbr] = depth[src]+1;
                dfs_helper(nbr, src);
            }
        }
    }

    void dfs(int src){
        for(int i=src; i<V; i++){
            if(depth[i] == -1){
                depth[i] = 0;
                dfs_helper(i, 0);
            }
        }

    }

    int lca_brute(int u, int v){
        if(u == v)  return u;


        if(depth[u] < depth[v]) swap(u, v);


        while(depth[u] != depth[v]){
            u = par[u];
        }

        while(u != v){
            u = par[u];
            v = par[v];
        }

        return u;
    }

};

int main(){
	int v, e;
	cin>>v>>e;
	Graph g(v+1);

	for(int i =0; i<e; i++){
		int x, y;
		cin>>x>>y;

		g.addEdge(x, y);
	}
    g.dfs(1);

    cout<<g.lca_brute(9, 15)<<endl;
    cout<<g.lca_brute(18, 15)<<endl;

    return 0;
}


