#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int coins[3] = {1, 3, 5};

    int N;
    cin>>N;

    int dp[100] = {0};

    for(int n=1; n<=N; n++){
        dp[n] = INT_MAX;
        for(int j=0; j<3; j++){
            if(n - coins[j] >= 0){
                int subprob = dp[n-coins[j]];
                dp[n] = min(dp[n], subprob+1);   
            }
        }
    }

    cout<<dp[N];

    return 0;
}

