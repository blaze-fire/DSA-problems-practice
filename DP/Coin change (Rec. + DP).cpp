// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

//Using Recursion
int CoinChange(int coin[], int n, int target){
	if(target == 0){
		return 1;
	}
	
	if(n == 0){
		return 0;
	}
	
	if(coin[n-1] <= target){
		return CoinChange(coin, n, target - coin[n-1]) + CoinChange(coin, n-1, target);
	}
	
	else{
		return CoinChange(coin, n-1, target);
	}
}

//Using DP
int CoinChangeDP(int coin[], int n, int target){
	int dp[n+1][target + 1];
	
	for(int i=0; i<n+1; i++){
		dp[i][0] = 1;
	}
	
	for(int j=1; j<target+1; j++){
		dp[0][j] = 0;
	}
	
	for(int i = 1; i<n+1; i++){
		for(int j=1; j<target+1; j++){
			if(coin[i-1] <= j){
				dp[i][j] = dp[i][j - coin[i-1]] + dp[i-1][j];
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
	
	//Recursion
	//cout<<CoinChange(coin, n, target);
	
	
	//using DP
	cout<<CoinChangeDP(coin, n, target);
	return 0;
}