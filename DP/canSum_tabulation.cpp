// Same CanSum problem but now with tabulation

#include <bits/stdc++.h>
using namespace std;

bool cansum(int target, int arr[], int size){
    bool table[target+1] = {false};
    table[0] = true;

    for(int i=0; i<(target+1); i++){
        if(table[i] == true){
            for(int j=i; j<size; j++){
                if((i+j) < target+1)
                    table[i+arr[j]] = true;
            }
        }
    }

    return table[target];

}

int main() {
    int arr[5] = {2, 4, 11, 10, 5};
    cout<<cansum(16, arr, 5)<<endl;
    return 0;
}
