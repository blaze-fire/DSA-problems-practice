#include<bits/stdc++.h>
using namespace std;
    
class Graph
{
    int V;
    vector<int> *adj;

public:

    Graph(int v){
        V = v;
        adj = new vector<int> [V];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    void dfs_helper(int src, bool visited[]){
        visited[src] = true;

        cout<<src<<"    ";

        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }

    void connected_componets(){
        bool visited[V] = {false};
        int cnt = 0;
        
        for(int i =0; i<V; i++){
            
            if(!visited[i]){
                cnt++;
                cout<<"Connected Components are : "<<endl;
                dfs_helper(i, visited);
            }
        
        }

        cout<<cnt;

    }
};


int main()
{
    
    Graph g(9);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 8);

    g.connected_componets();
    return 0;
}
