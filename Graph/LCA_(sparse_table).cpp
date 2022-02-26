/*Input:
19
1 2
2 4
2 5
5 6
6 7
6 8
6 9
1 3
3 10
3 11
10 17
11 12
17 18
17 19
12 13
12 14
12 15
15 16

Output:
	1
	3

*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100000, M = 22;
vector<int> l[N];

int depth[N];
int Par[N][M];
	
void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
}
	
void dfs_helper(int src, int par){
	for(int nbr: l[src]){
		if(nbr != par){
			depth[nbr] = depth[src] + 1;
			dfs_helper(nbr, src);
		}
	}
	return;
}

void dfs(int src, int par){
	dfs_helper(src, par);
}

void calc_sparse_table(int src, int par){
	Par[src][0] = par;
	for(int j=1; j<M; j++){
		Par[src][j] = Par[Par[src][j-1]][j-1];
	}

	for(int nbr: l[src]){
		if(nbr != par){
			calc_sparse_table(nbr, src);
		}
	}
}

int lca_depth(int u, int v){
	if(u == v)	return u;

	//assume u is at grater depth
	if(depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	for(int i = M-1; i>=0 ; i--){
		if((diff >> i) & 1){
			u = Par[u][i];
		}
	}

	//after this u  and v are on same level
	//v was ancestor of u
	if(u == v){
		return u;
	}

	for(int i = M-1; i>=0 ; i--){
		if(Par[u][i] != Par[v][i]){
			u = Par[u][i];
			v = Par[v][i];
		}
	}

	//I am standing on different nodes
	return Par[u][0]; 	//or return Par[v][0] same thing

}
	

int main() {
	// your code goes here
	int e;
	cin>>e;
	
	for(int i =0; i<e; i++){
		int x, y;
		cin>>x>>y;
		
		l[x].push_back(y);
		l[y].push_back(x);
	}
	dfs(1, 0);
	calc_sparse_table(1,0);
	cout<<lca_depth(9, 15)<<endl;
	cout<<lca_depth(18, 15)<<endl;
	
	
	return 0;
}