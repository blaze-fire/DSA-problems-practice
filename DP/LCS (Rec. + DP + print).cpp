// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

//Using Recursion
int lcs(string x, string y, int m, int n){
	if(m == 0 or n == 0){
		return 0;
	}
	
	if(x[m-1] == y[n-1]){
		return 1 + lcs(x, y, m-1, n-1);
	}
	
	else{
		return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
	}
}

//Using DP
int lcs_DP(string x, string y, int m, int n){
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
	
	//Print lcs
	
	int i=m, j=n;
	string str;
	while(i>0 and j>0){
		
		if(x[i-1] == y[j-1]){
			str.push_back(x[i-1]);
			i--;
			j--;
		}
		
		else{
			if(dp[i][j-1] > dp[i-1][j]){
				j--;
			}
			
			else{
				i--;
			}
		}
	}
	
	reverse(str.begin(), str.end());
	
	cout<<str<<endl;
	
	return dp[m][n];
}


int main() {
	// your code goes here
	string x = "abcdgh", y = "abedfhr";
	int m = x.size(), n = y.size();
	
	//using recursion
	//cout<<lcs(x, y, m, n);
	
	
	//using dp
	cout<<lcs_DP(x, y, m, n);
	
	return 0;
}