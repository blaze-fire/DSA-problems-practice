#include<bits/stdc++.h>
using namespace std;

class DFS{
    int arr[100][100];
    int V;
    bool *visited;
public:
    DFS(int v){
        
        V = v;

        visited = new bool [V];

        for(int i=0; i<V; i++){
            visited[i] = false;
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                arr[i][j] = 0;
            }
        }

    }

    void addEdge(int x, int y){
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    void dfs_utils(int src){
        visited[src] = true;

        cout<<src<<"    ";

        for(int i=0; i<V; i++){
            if((arr[i][src] == 1) && !visited[i]){
                dfs_utils(i);
            }
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

    g.dfs_utils(0);

    return 0;
}