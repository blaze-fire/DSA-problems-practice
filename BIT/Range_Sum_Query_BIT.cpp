#include <bits/stdc++.h>
using namespace std;

int BIT[1000] = {0};

void update(int i, int inc, int n){
	while(i <= n){
		BIT[i] += inc;
		i = i + (i&(-i));
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
		update(i, arr[i], n);
	}
	
	int q;
	cin>>q;
	
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<query(r) - query(l-1)<<endl;		
	}
	
	return 0;
}