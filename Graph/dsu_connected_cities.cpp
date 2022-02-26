#include <bits/stdc++.h>
using namespace std;

/*

Q-There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format:
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints:
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

eg.:
5 3
0 1
0 4
2 3

6 ways
*/

class DFS{

    int V;
    vector<int> *adj;
public:

    DFS(int v){
        this->V = v;
        adj = new vector<int> [V];
    }

    void addEdge(int x, int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void dfs_utils(int src, bool visited[], int &size){
        visited[src] = true;

        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                size++;
                dfs_utils(nbr, visited, size);
            }
        }
    }

    void dfs(){
        bool visited[V] = {false};

        int size = 1;

        for(int i=0; i<V; i++){
            for(auto edge: adj[i]){
                if(!visited[edge]){
                    int comp_size=1;
                    dfs_utils(edge, visited, comp_size);
                    size *= comp_size; 
                }
            }
        }

        cout<<size<<endl;
    }
};


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int v,e;
    cin>>v>>e;

    DFS g(v);

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;

        g.addEdge(x, y);        
    }

    g.dfs();

    return 0;
}
