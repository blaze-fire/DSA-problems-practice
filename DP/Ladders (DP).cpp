#include <bits/stdc++.h>
using namespace std;

int ladders_dp(int n, int k){
	int dp[n+1] = {0};
	
	dp[0] = 1;
	int sum_so_far = dp[0];
	for(int i=1; i<=k; i++){
		dp[i] += sum_so_far;
		sum_so_far += dp[i];
	}

	for(int i=k+1; i<n+1; i++){
		for(int j=i-1; j>=i-k; j--){
			dp[i] += dp[j];
		}
	}
	
	return dp[n];
}

int main() {
	// your code goes here
	int n=5, k=3;
	
	cout<<ladders_dp(n, k);
	return 0;
}