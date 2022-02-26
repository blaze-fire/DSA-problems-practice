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

    void topological_sort(){
        
        vector<int> indegree(V, 0);

        for(int i=0; i<V; i++){
            for(auto itr: adj[i]){
                indegree[itr]++;
            }
        }


        queue<int> Q;

        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                Q.push(i);
            }
        }

        while(!Q.empty())
        {
            
            int top = Q.front();
            
            cout<<top<<endl;

            Q.pop();

            for(auto nbr: adj[top])
            {
            
                indegree[nbr]--;

                if(indegree[nbr] == 0){
                    Q.push(nbr);
                }
            
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

    g.topological_sort();

    return 0;
}