#include<bits/stdc++.h>
using namespace std;


bool dfs_helper(vector<int> adj[], int *visited, int src, int parent, int color){
    
    visited[src] = color;
    cout<<color<<endl;
    for(auto nbr: adj[src]){
        if(visited[nbr] == 0){
            bool check_cycle = dfs_helper(adj, visited, nbr, src, 3-color);

            if(check_cycle == false)
                return false;
        }

        else if(nbr != parent && visited[nbr] == color){
            return false;
        }
    }

    return true;
}

bool dfs(vector<int> adj[], int v){
    int visited[v] = {0};

    bool ans = dfs_helper(adj, visited, 0, -1, 1);

    for(int i=0; i<v; i++){
        cout<<i<<" color is "<<visited[i]<<endl;
    }

    return ans;
}

  
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int V, E;
    cin>>V>>E;

    vector<int> adj[V];

    while(E--){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(dfs(adj, V)){
        cout<<"Graph is Bipartite";
    }

    else{   
        cout<<"Not Bipartite";
    }
    
    return 0;
}