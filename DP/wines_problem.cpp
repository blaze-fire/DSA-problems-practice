#include <bits/stdc++.h>
using namespace std;

int max_profit(int wines[], int i, int j, int y, int dp[][100]){
    if(i>j){
        return 0;
    }

    if(dp[i][j] != 0){
        return dp[i][j];
    }

    int profit1 = wines[i]*y + max_profit(wines, i+1, j, y+1, dp);
    int profit2 = wines[j]*y + max_profit(wines, i, j-1, y+1, dp);
    return dp[i][j] = max(profit1, profit2);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int y=1;
    int dp[100][100] = {0};

    cout<<max_profit(wines, 0, n-1, y, dp);


    return 0;
}

