#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int dp[100] = {0};
    int n;
    cin>>n;

    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++){

        int n1, n2, n3;
        n1 = n2 = n3 = INT_MAX;

        if(i%3 == 0)
            n1 = dp[i/3];
        
        else if(i%2 == 0){
            n2 = dp[i/2];
        }

        else 
            n3 = dp[i-1];

        dp[i] = min(min(n1, n2), n3) + 1;
        
    }

    for(int i=0; i<=n; i++){
        cout<<dp[i]<<"  ";
    }

    return 0;
}
