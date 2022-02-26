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

    bool dfs_helper(int visited[], int src, int parent, int color){
        
        visited[src] = color;
        for(auto nbr: l[src]){
            if(visited[nbr] == 0){
                bool sub_prob = dfs_helper(visited, nbr, src, 3-color); //as color either 1 or 2, so if color is 1 the pass 3-1 = 2

                if(sub_prob == false)
                    return false;
            }

            else if(nbr != parent && visited[nbr] == color){
                return false;
            }
        }

        return true;
    }

    bool dfs(int src){
        int visited[V] = {0};

        for(int i=0; i<V; i++){
            if(visited[i] == 0){
                bool check = dfs_helper(visited, i, -1, 1);
                if(check == false){
                    return check;
                }
            }
        } 

        return true;
    }
};


  
int main()
{
     
	Graph g(6);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(5, 3);

    if(g.dfs(1)){
        cout<<"Graph is Bipartite"<<endl;
    }

    else{   
        cout<<"Not Bipartite";
    }
    
    return 0;
}