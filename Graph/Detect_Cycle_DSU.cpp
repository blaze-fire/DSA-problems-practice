#include<bits/stdc++.h>
using namespace std;

class DSU{
    int V;
    list<pair<int, int>> adj;

public:
    
    DSU(int v){
        this->V = v;
    }

    void addEdge(int x, int y){
        adj.push_back(make_pair(x, y));
    }

    int findSet(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }

        return findSet(parent[i], parent);
    }

    void union_set(int x, int y, int parent[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if(s1 != s2){
            parent[s1] = s2;
        }
    }

    bool detect_cycle(){
        int *parent = new int [V];

        for(int i=0; i<V; i++){
            parent[i] = -1;
        }

        for(auto edge: adj){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2){
                union_set(s1, s2, parent);
            }

            else{
                cout<<"Same parent "<<s1<<" and "<<s2<<endl;
                delete [] parent;
                return true;
            }

        }

        cout<<"No cycle"<<endl;
        delete [] parent;
        return false;
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

    DSU g(v);

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g.addEdge(x, y);
    }

    g.detect_cycle();

    return 0;
}

/*
Eg.:

4 4
0 1
1 2
2 3
3 0

*/