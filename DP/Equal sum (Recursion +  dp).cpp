// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

bool EqualSumPartition(int arr[], int n, int target){
	if(target == 0){
		return true;
	}
	
	if(n == 0){
		return false;
	}
	
	if(arr[n-1] <= target)
		return EqualSumPartition(arr, n-1, target - arr[n-1]) or EqualSumPartition(arr, n-1, target);
	
	else
		return EqualSumPartition(arr, n-1, target);
}

bool EqualSumPartition_DP(int arr[], int n, int target){
	int dp[n+1][target+1];
	
	for(int i=0; i<n+1; i++)
		dp[i][0] = true;
	
	for(int j=1; j<target+1; j++){
		dp[0][j] = false;
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<target+1; j++){
			
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
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
	int arr[] = {1, 5, 11, 5};
	int n = sizeof(arr)/sizeof(int);
	
	int arrSum = 0;
	
	for(int i=0; i<n; i++){
		arrSum += arr[i];
	}
	
	if(arrSum%2 != 0){
		cout<<"false";
	}
	
	else{
		int target = arrSum/2;
		
		//recursive 
		//bool ans = EqualSumPartition(arr, n, target);
		
		//Using DP
		bool ans = EqualSumPartition_DP(arr, n, target);
		
		if(ans){
			cout<<"true";
		}
		
		else{
			cout<<"false";
		}
	}
	return 0;
}