
// Faster than segment tree implementation
#include <bits/stdc++.h>
using namespace std;

int getpar(int i, int parent[]){
	if(parent[i] == i){
		return i;
	}
	
	return parent[i] = getpar(parent[i], parent);
}

void unite(int x, int y, int parent[]){
	int s1 = getpar(x, parent);
	int s2 = getpar(y, parent);
	
	if(s1 != s2){
		parent[s1] = max(parent[s1], parent[s2]);
		parent[s2] = max(parent[s1], parent[s2]);
	}
}

int main() {

	int m, n;
	cin>>m>>n;
	
	int result[m+2] = {0};
	int parent[m+2];
	
	for(int i=0; i<m+2; i++){
		parent[i] = i;
	}
	
	int l[n], r[n], color[n];
	
	for(int i=0; i<n; i++){
		cin>>l[i]>>r[i]>>color[i];	
	}

	for(int i=n-1; i>=0; i--){
		int index = getpar(l[i], parent);
		
		//index should be less than rightmost index of query as if greater than out of bounds
		while(index <= r[i]){
			
			result[index] = color[i];
			
			//unite the indexes so as to get the rightmost index from where to start coloring
			unite(index, index+1, parent);
			
			//get the rightmost index after you unite index and index+1
			index = getpar(index, parent);
		}
	}	
	
	for(int i=1; i<=m; i++){
		cout<<result[i]<<endl;
	}
	
	return 0;
}