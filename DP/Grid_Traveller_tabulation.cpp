#include <bits/stdc++.h>
using namespace std;

int gridtravel(int m, int n){   
    int arr[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            arr[i][j] = 0;   
        }
    }

    arr[1][1] = 1;

    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i+1 <= m)
                arr[i+1][j] += arr[i][j];

            if(j+1 <= n)
                arr[i][j+1] += arr[i][j];   
        }
    }

    return arr[m][n];
}

int main() {
    cout<<gridtravel(5, 10)<<endl;
    return 0;
}
