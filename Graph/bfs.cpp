#include<bits/stdc++.h>
using namespace std;

class BFS{
    int V;
    vector<int> *adj;

public:

    BFS(int v){
        V = v+1;
        adj = new vector<int> [V];
    }

    void addEdge(int x, int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    void sol(int src){

        bool visited[V] = {false};
    
        queue<int> Q;
    
        Q.push(src);
    
        visited[src] = true;
    
            
        while(!Q.empty()){
            int top = Q.front();
            Q.pop();
            
            visited[top] = true;
            cout<<top<<"    ";

            for(auto nbr: adj[top]){
                if(!visited[nbr]){
                    Q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    
        
    }
};

int main(){
    
    int v, e;

    cin>>v>>e;

    BFS g(v);

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }    

    g.sol(0);


    cout<<endl;

    return 0;
    
}

