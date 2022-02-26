// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

//recursive case
bool subset_sum(int arr[], int n, int sum){
	if(sum == 0){
		return true;
	}
	
	if(n == 0){
		return false;
	}
	
	if(arr[n-1] <= sum){
		return subset_sum(arr, n-1, sum - arr[n-1]) or subset_sum(arr, n-1, sum);
	}
	
	else{
		return subset_sum(arr, n-1, sum);
	}
}

int subset_sum_diff_DP(int arr[], int n, int sum){
	bool dp[n+1][sum+1];
	
	for(int i=0; i<n+1; i++){
		dp[i][0] = true;
	}
	
	for(int j=1; j<sum+1; j++){
		dp[0][j] = false;
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
			}
			
			else{
				dp[i][j] = dp[i-1][j];
			}
			
		}
	}
	
	vector<int> ans;
	
	for(int j=0; j<=sum; j++){
		if(dp[n][j]){
			ans.push_back(j);
		}
	}
	
	int min_ = INT_MAX;
	for(int i=0; i<=ans.size()/2; i++){
		min_ = min(min_, abs(sum - 2*ans.at(i)));
	}
	
	return min_;
}

int main() {
	// your code goes here
	int arr[] = {1, 6, 10, 5};
	int n = sizeof(arr)/sizeof(int);
	
	int sum = 0;
	
	for(int i=0; i<n; i++){
		sum += arr[i]; 	
	}
	
	vector<int> ans;
	
	//Using Recursion
	/*
	ans.push_back(0);
	for(int i=1; i<=sum; i++){
		if(subset_sum(arr, n, i)){
			ans.push_back(i);
		}
	}
	
	int min_ = INT_MAX;
	
	for(int i=0; i<= ans.size()/2; i++){
		min_ = min(min_, abs(2*ans.at(i) - sum));
	}
	
	cout<<min_;
	*/
	
	//Using DP
	cout<<subset_sum_diff_DP(arr, n, sum);
	
	return 0;
}