#include <bits/stdc++.h>
using namespace std;

int MaxSubarraySum(int arr[], int n){
	int dp[n+1];
	
	dp[0] = arr[0]>0?arr[0]:0;
	
	int max_so_far = INT_MIN;
	
	for(int i=1; i<n; i++){
		dp[i] = dp[i-1] + arr[i];
		if(dp[i] < 0){
			dp[i] = 0;
		}
		max_so_far = max(max_so_far, dp[i]);
	}
	
	return max_so_far;
}

//space optimized

int MaxSubarraySumOptimized(int arr[], int n){
	int cur;
	cur = arr[0]>0?arr[0]:0;
	
	int max_so_far = INT_MIN;
	
	for(int i=1; i<n; i++){
		cur += arr[i];
		if(cur < 0){
			cur = 0;
		}
		max_so_far = max(max_so_far, cur);
	}
	
	return max_so_far;
	
}

int main() {
	// your code goes here
	int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
	int n = sizeof(arr)/sizeof(int);
	
	//cout<<MaxSubarraySum(arr, n);
	
	
	//Space Optimized
	cout<<MaxSubarraySumOptimized(arr, n);
	return 0;
}