/*
Input:
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

int tin[N], tout[N], timer;
int Par[N][M];

void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
}
	
void dfs_helper(int src, int par){
	tin[src] = ++timer;
	for(int nbr: l[src]){
		if(nbr != par){
			dfs_helper(nbr, src);
		}
	}
	tout[src] = timer;
	return;
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

void dfs(int src, int par){
	tin[0] = 0; 
	tout[0] = N+1;		//universal parent
	dfs_helper(src, par);
}
	
bool isAncestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca_euler_tree(int u, int v){
	// us is ancestor of v
	if(isAncestor(u, v))	return u;
	if(isAncestor(v, u))	return v;

	for(int i=M-1; i>=0; i--){
		//Parent[u][i] is not ancestor of v then move to it
		if(!isAncestor(Par[u][i], v)){
			u = Par[u][i];
			v = Par[v][i];
		}
	}		

	return Par[u][0];
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
	timer=0;
	dfs(1, 0);
	calc_sparse_table(1,0);
	cout<<lca_euler_tree(9, 15)<<endl;
	cout<<lca_euler_tree(18, 15)<<endl;
	
	
	return 0;
}
