#include <bits/stdc++.h>
using namespace std;

int MaxSubArraySum(int arr[], int n){

    int maxSum = arr[0]>0?arr[0]:0;
    int tempSum = maxSum;
    for(int i=1; i<n; i++){
        tempSum += arr[i];
        
        if(tempSum < 0)
            tempSum = 0;

        maxSum = max(maxSum, tempSum);
    }

    return maxSum;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int arr[] = {-3, 2, 5,-1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr)/sizeof(int);

    cout<<MaxSubArraySum(arr, n);

    return 0;
}

