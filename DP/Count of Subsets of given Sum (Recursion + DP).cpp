// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

int CountSubsets(int arr[], int n, int sum){
	if(sum == 0){
		return 1;
	}
	
	if(n == 0){
		return 0;
	}
	
	if(arr[n-1] <= sum){
		return CountSubsets(arr, n-1, sum - arr[n-1]) + CountSubsets(arr, n-1, sum);
	}
	
	else{
		return CountSubsets(arr, n-1, sum);
	}
}

int CountSubsetsDP(int arr[], int n, int sum){
	int dp[n+1][sum+1];
	
	for(int i=0; i<n+1; i++){
		dp[i][0] = 1;
	}
	
	for(int j=1; j<sum+1; j++){
		dp[0][j] = 0;
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

int main() {
	// your code goes here
	int arr[] = {2, 3, 5, 6, 8, 10};
	int n = sizeof(arr)/sizeof(int);
	
	int sum = 10;
	
	//Recursive Case
	//int ans = CountSubsets(arr, n, sum);
	//cout<<ans;
	
	
	//DP case
	int ans_dp = CountSubsetsDP(arr, n, sum);
	cout<<ans_dp;
	
	return 0;
}