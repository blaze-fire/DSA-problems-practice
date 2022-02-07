#include<bits/stdc++.h>
using namespace std;

class DFS{
    vector<int> *adj;
    int V;

public:

    DFS(int v){
        
        V = v;

        adj = new vector<int> [V];

    }

    void addEdge(int x, int y){
        adj[x].push_back(y);
    }

    void dfs_utils(int src, bool visited[], list<int> &ordering){
        visited[src] = true;

        for(auto itr: adj[src]){
            if(!visited[itr]){
                dfs_utils(itr, visited, ordering);
            }
        }

        ordering.push_front(src);
    }

    void dfs(){

        list<int> ordering;
        bool visited[V] = {false};
    
        for(int i=0; i<V; i++){
            
            if(!visited[i])
                dfs_utils(i, visited, ordering);
        
        }
        
        for(auto itr: ordering){
            cout<<itr<<endl;
        }
    }

};


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int v, e;
    cin>>v>>e;

    DFS g(v);

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;

        g.addEdge(x, y);
    }

    g.dfs();

    return 0;
}