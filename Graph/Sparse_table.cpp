/* Input:
7
1 2 3 4 5 6 7

Output: 1

*/
#include <bits/stdc++.h>
using namespace std;

struct sparse_table{
	vector<vector<int>> mat;	//2d matrix
	int n, m;	//size and log
	vector<int> p2;
	
	void init(int _n, int _m){
		n = _n, m = _m;
		mat.resize(n);
		for(int i=0; i<n; i++)
			mat[i].resize(m);
		
		p2.resize(n+1);
		for(int i=2; i<=n; i++){
			p2[i] = p2[i/2] + 1;
		}
	}
	
	void build(int arr[]){
		for(int i=0; i<n; i++){
			mat[i][0] = arr[i];
		}
		
		for(int j=1; j<m; j++){
			for(int i=0; i + (1 << (j)) <= n; i++){
				mat[i][j] = min(mat[i][j-1], mat[i+ (1 << (j-1))][j-1]);
			}
		}
	}
	
	int query(int l, int r){
		int pw = p2[r-l]; 
		return min(mat[l][pw], mat[r-(1 << pw)-1][pw]);
	}
	
};

int main() {
	// your code goes here
	int m;
	cin>>m;
	int arr[m+1];
	
	for(int i=0; i < m; i++){
		cin>>arr[i];
	}
	
	int n = ceil(log(m)/log(2));
	
	sparse_table s;
	s.init(m, n);
	s.build(arr);
	cout<<s.query(0, 6);
	return 0;
}