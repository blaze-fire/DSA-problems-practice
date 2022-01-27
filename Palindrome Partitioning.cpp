#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int j){
	while(i<j){
		if(str[i] == str[j]){
			i++;
			j--;
		}
		else{
			return false;
		}		
	}
	
	return true;
}

int PalindromePartition(string str, int i, int j){
	if(i >= j){
		return 0;
	}
	
	if(isPalindrome(str, i, j)){
		return 0;
	}
	
	int mn = INT_MAX;
	
	for(int k=i; k<=j-1; k++){
		int temp_ans = PalindromePartition(str, i, k) + PalindromePartition(str, k+1, j) + 1;
		mn = min(mn, temp_ans);
	}
	
	return mn;
	
}

int static dp[1001][1001];

int PalindromePartitionFast(string str, int i, int j){
	if(i >= j){
		return 0;
	}
	
	if(isPalindrome(str, i, j)){
		return 0;
	}
	
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	
	int mn = INT_MAX;
	
	for(int k=i; k<=j-1; k++){
		int temp_ans = PalindromePartition(str, i, k) + PalindromePartition(str, k+1, j) + 1;
		mn = min(mn, temp_ans);
	}
	
	return dp[i][j] = mn;
	
}

int main() {
	// your code goes here
	string str = "nitik";
	int n = str.size();
	memset(dp, -1, sizeof(dp));
	
	//cout<<PalindromePartition(str, 0, n-1);
	cout<<PalindromePartitionFast(str, 0, n-1);
	return 0;
}