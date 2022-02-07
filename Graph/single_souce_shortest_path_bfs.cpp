#include<bits/stdc++.h>
using namespace std;


void addEdge(int x, int y, vector<int> adj[]){
    adj[x].push_back(y);
}

void sol(int src, vector<int> adj[], int v){
    queue<int> q;

    q.push(src);

    int dist[v+1];

    for(int i=0; i < v+1; i++){
        dist[i] = -1;
    }

    dist[src] = 0;


    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(auto itr: adj[top]){
            if(dist[itr] == -1){
                q.push(itr);
                dist[itr] = dist[top] + 1;
            }
        }
    }

    for(int i=0; i < v; i++){
        cout<<dist[i]<<"    ";
    }

}

int main(){

    int v, e;

    cin>>v>>e;

    vector<int> adj[v];
    

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        addEdge(u, v, adj);
    }    

    sol(0, adj, v);
    
    cout<<endl;

    return 0;
    
}

