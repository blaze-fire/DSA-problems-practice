#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int v){
        V = v;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    void bfs(int src, int dest){
        queue<int> q;

        q.push(src);

        int dist[V+1] = {-1};
        int parent[V] = {-1};
        bool visited[V] = {false};

        dist[src] = 0;
        parent[src] = src;
        visited[src] = true;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto itr: l[top]){
                if(!visited[itr]){
                    q.push(itr);
                    visited[itr] = true;
                    dist[itr] = dist[top] + 1;
                    parent[itr] = top;
                }
            }
        }

        //to print shortest distance to a particular node
        for(int i=0; i<V; i++){
            cout<<"Shortest distance to node "<<i<<" : "<<dist[i]<<endl;
        }

        //to print the path
        if(dest != -1){
            int temp = dest;
            while(temp != src){
                cout<<temp<<" -- ";
                temp = parent[temp];
            }
            cout<<src<<endl;
        }
    }
};



int main(){

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.bfs(1, 6);

    return 0;
    
}

