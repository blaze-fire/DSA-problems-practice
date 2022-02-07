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

    bool cycle_helper(int src, bool visited[], bool stack[]){
        visited[src] = true;
        stack[src] = true;

        for(auto nbr: adj[src]){
            if(stack[nbr] == true){
                return true;
            }

            else if(!visited[nbr]){
                bool cycle_check = cycle_helper(nbr, visited, stack);

                if(cycle_check == true){
                    return true;
                }
            }
        }

        stack[src] = false;
        return false; 

    }

    void cycle_detector(){
        bool visited[V] = {false};
        bool stack[V] = {false};


        if(cycle_helper(0, visited, stack) == true){
            cout<<"Cycle Present"<<endl;
        }

        else{
            cout<<"No Cycle"<<endl;
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

    g.cycle_detector();

    return 0;
}

/*
Eg:

6 7
0 1
0 5
1 2
2 3
3 4
4 2
4 5

*/