#include<bits/stdc++.h>
using namespace std;

# define ull unsigned long long
int dp[101][181][3];

int solve(string& arr, int n, int x, bool tight){
    
    if(x<0) return 0;

    if(n == 1){
        if(x>=0 && x<=9)
            return 1;

        else 
            return 0;
    }

    if(dp[n][x][tight] != -1)
        return dp[n][x][tight];

    int answer = 0;
    int ub = (tight) ? (arr[arr.length() - n] - '0'):9;

    for(int dig=0; dig<=ub; dig++){
        answer += solve(arr, n-1, x-dig, (tight&(ub==dig)));
    }

    return dp[n][x][tight] = answer;
}


int main() {

    memset(dp, -1, sizeof dp);

    string s = "1120343423443535";

    cout<<solve(s, s.length(), 15, 1);
    
    return 0;
}
