// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

int SCS_dp(string x, string y, int m, int n){
	int dp[m+1][n+1];
	
	for(int i=0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			
			else if(x[i-1] == y[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main() {
	// SCS will be (m + n - LCS)
	string a="geek", b="eke";
	int m = a.size(), n = b.size();
	
	int scs = SCS_dp(a, b, m, n);
	cout<<(m + n - scs);
	
	return 0;
}