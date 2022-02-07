// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

//Using recursion
int minCoinExchange(int coin[], int n, int target, int &ans){
	if(target == 0){
		return 1;
	}
	
	if(n == 0){
		return INT_MAX;
	}
	
	if(coin[n-1] <= target){
		int left = minCoinExchange(coin, n, target - coin[n-1], ans) + 1;
		int right = minCoinExchange(coin, n-1, target, ans);
		ans = min(min(left, right), ans);
		return ans;
	}
	
	else{
		return minCoinExchange(coin, n-1, target, ans);
	}
}


//Using DP
int minCoinExchangeDP(int coin[], int n, int target){
	int dp[n+1][target+1];
	
	for(int i=0; i<n+1; i++){
		dp[i][0] = 0;
	}
	
	for(int j=1; j<target+1; j++){
		dp[0][j] = INT_MAX-1;
	}
	
	for(int j=1; j<target+1; j++){
		if(j%coin[0] == 0){
			dp[1][j] = j/coin[0];
		}
		
		else{
			dp[1][j] = 0;
		}
	}	
	
	for(int i=2; i<n+1; i++){
		for(int j=1; j<target+1; j++){
			if(coin[i-1] <= j){
				dp[i][j] = min(1 + dp[i][j - coin[i-1]], dp[i-1][j]);
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
	int coin[] = {1, 2, 3};
	int n = sizeof(coin)/sizeof(int);
	
	int target = 5;
	int ans = INT_MAX;
	
	//Using recursion
	//cout<<minCoinExchange(coin, n, target, ans);
	
	
	//Using DP
	cout<<minCoinExchangeDP(coin, n, target);
	
	return 0;
}