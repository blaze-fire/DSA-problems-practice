#include <bits/stdc++.h>

using namespace std;


class DFS{
    int V;
    list<pair<int, int>> l ;
public:

    DFS(int v){
        V = v;
    }

    void addEdge(int x, int y){
        l.push_back(make_pair(x, y));
    }


    //path compression
    int findSet(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }

        return parent[i] = findSet(parent[i], parent);
    }


    //union by rank optimization
    void union_set(int i, int j, int parent[], int rank[]){
        int s1 = findSet(i, parent);
        int s2 = findSet(j, parent);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }

            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    bool containsCycle(){
        int *parent = new int [V];
        int rank[V];

        for(int i=0; i<V; i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        for(auto edge: l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2){
                union_set(s1, s2, parent, rank);
                
            }        

            else{
                delete [] parent;
                return true;
            }
        }
        
        delete [] parent;
        return false;

    }

};

int main() {
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

    if(g.containsCycle()){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
