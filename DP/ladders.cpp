#include <bits/stdc++.h>
using namespace std;

int ladders(int n, int k){

    int dp[100] = {0};
    dp[0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-j >= 0){
                dp[i] += dp[i-j]; 
            }
        }
    }

    return dp[n];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin>>n>>k;

    cout<<ladders(n, k);

    return 0;
}

