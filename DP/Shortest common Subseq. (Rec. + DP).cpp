// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;

int SCS_dp(string a, string b, int m, int n){

	int dp[m+1][n+1];
	
	for(int i=0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			
			if(i == 0 || j == 0){
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

	int i = m, j=n;
    string res;

    while(i > 0 and j > 0){

        if(a[i-1] == b[j-1]){
            res.push_back(a[i-1]);
            i--, j--;
        }

        else{
            if(dp[i][j-1] > dp[i-1][j]){
                res.push_back(b[j-1]);
                j--;
            }

            else if(dp[i][j-1] < dp[i-1][j]){
                res.push_back(a[i-1]);
                i--;
            }

            else{
				if(m>n){
					res.push_back(b[j-1]);
					j--;
				}
				else{
					res.push_back(a[i-1]);
					i--;
				}
			}
        }
    }

    while(i>0){
        res.push_back(a[i-1]);
        i--;
    }

    while(j > 0){
        res.push_back(b[j-1]);
        j--;
    }

    reverse(res.begin(), res.end());
    cout<<res<<endl;

	return dp[m][n];
}

int main() {
	// SCS will be (m + n - LCS)
	string a="abcdaf", b="acbcf";
	int m = a.size(), n = b.size();
	
	int scs = SCS_dp(a, b, m, n);
	cout<<(m + n - scs);
	
	return 0;
}
