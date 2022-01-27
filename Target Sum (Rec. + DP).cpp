// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

int targetSum(int arr[], int n, int target){
	if(target == 0){
		return 1;
	}
	
	if(n == 0){
		return 0;
	}

	if(arr[n-1] <= target){
		return targetSum(arr, n-1, target - arr[n-1]) + targetSum(arr, n-1, target);
	}
	
	else{
		return targetSum(arr, n-1, target);
	}
}

int targetSumDP(int arr[], int n, int target){
	int dp[n+1][target+1];
	
	for(int i=0; i<n+1; i++){
		dp[i][0] = 1;
	}
	
	for(int j=1; j < target+1; j++){
		dp[0][j] = 0;
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<target+1; j++){
			
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
			}
			
			else{
				dp[i][j] = dp[i-1][j];
			}
			
		}
	}
	
	return dp[n][target];
}

int main() {
	// your code goes here
	int arr[] = {1, 2, 2, 3};
	int n = sizeof(arr)/sizeof(int);
	
	int diff = 2;
	
	int sum = 0;
	
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	
	int target = (sum + diff)/2;

	//Recursive
	//int count = targetSum(arr, n, target);
	//cout<<count;
	
	//Dynamic Programming
	int countDP = targetSumDP(arr, n, target);
	cout<<countDP;
	
	return 0;
}