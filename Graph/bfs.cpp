#include<bits/stdc++.h>

using namespace std;

class graph{
    int v;
    list <int> *l;

public:
    graph(int data){
        v = data;
        l = new list<int> [v];
    }


    void addEdge(int u, int v, bool undir=true){
        l[u].push_back(v);

        if(undir){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int i=0; i<v; i++){
            cout<<i<<" : ";
            for(auto elm = l[i].begin(); elm != l[i].end(); elm++){
                cout<<*elm<<" ";
            }
            cout<<endl;
        }
    }


    void bfs(int src){
        queue<int> q;
        q.push(src);
        bool visited[v] = {false};
        visited[src] = true;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            cout<<top<<" ";

            for(auto elm : l[top]){
                if(!visited[elm]){
                    q.push(elm);
                    visited[elm] = true;
                }
            }
        }
    }
};





int main(){
    graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 4);

    g.bfs(1);               //Expected output: 1 0 2 4 3 5

//     g.print();
    cout<<endl;
    return 0;
}
