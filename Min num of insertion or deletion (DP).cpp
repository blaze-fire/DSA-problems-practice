// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n){
	int dp[m+1][n+1];
	
	for(int i=0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}
			
			else if(a[i-1] == b[j-1]){
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
	// your code goes here
	string a = "heap", b = "pea";
	int m = a.size(), n = b.size();
	
	//deletion would be : len(a) - lcs;
	//insertion would be : len(b) - lcs;
	int LCS = lcs(a, b, m, n);
	
	int insertion = m - LCS;
	int deletion = n - LCS;
	
	cout<<"insertion : "<<insertion<<" , deletion : "<<deletion<<endl;
	
	return 0;
}