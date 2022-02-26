/*
Input:
5
5 2 1 4 3

Output:
6
 */
#include <bits/stdc++.h>
using namespace std;

int BIT[1000] = {0};

void update(int idx, int val, int n){
	while(idx <= n){
		BIT[idx] += val;
		idx = idx + (idx&(-idx));
	}
}

int query(int i){
	int ans = 0;
	while(i > 0){
		ans += BIT[i];
		i = i - (i&(-i));
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	// Inversion Counts
	int ans = 0;
	for(int i=n; i>=1; i--){
		ans += query(arr[i] - 1);
		update(arr[i], 1, n);
	}
	cout<<ans<<endl;
	
	return 0;
}