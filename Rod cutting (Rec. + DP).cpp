// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

//Recursive
int rodcutting(int length[], int price[], int n, int target){
	if(target == 0 || n == 0){
		return 0;
	}
	
	if(length[n-1] <= target){
		return max(price[n-1] + rodcutting(length, price, n, target - length[n-1]), rodcutting(length, price, n-1, target));
	}
	
	else{
		return rodcutting(length, price, n-1, target);
	}
	
}


//Using DP
int rodcuttingDP(int length[], int price[], int n, int target){
	int dp[n+1][target+1];
	
	for(int i=0; i<n+1; i++){
		for(int j=0; j<target+1; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}
			
			else if(length[i-1] <= j){
				dp[i][j] = max(price[i-1] + dp[i][j - length[i-1]], dp[i-1][j]);
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
	int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	
	int n = sizeof(length)/sizeof(int);
	
	int target = 8;
	
	//cout<<rodcutting(length, price, n, target);
	
	//Using DP
	cout<<rodcuttingDP(length, price, n, target);
	return 0;
}