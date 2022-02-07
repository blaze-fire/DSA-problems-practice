#include <iostream>
using namespace std;

struct Pair{
    int max;
    int min;
};

struct Pair getMinMax(int arr[], int n){
    struct Pair MinMax;
    int i;

    // if n is even
    if(n%2 == 0){
        if(arr[0] > arr[1]){
            MinMax.max = arr[0];
            MinMax.min = arr[1];
        }

        else{
            MinMax.max = arr[1];
            MinMax.min = arr[0]; 
        }

        i = 2; 
    }

    // if n is odd
    else{
        MinMax.max = arr[0];
        MinMax.min = arr[0];
        i = 1;
    }

    while(i < n-1){

        if(arr[i] > arr[i+1]){
            
            if(arr[i] > MinMax.max){
                MinMax.max = arr[i];
            }

            if(arr[i+1] < MinMax.min){
                MinMax.min = arr[i+1];
            }

        }

        else{
            if(arr[i+1] > MinMax.max){
                MinMax.max = arr[i+1];
            }

            if(arr[i] < MinMax.min){
                MinMax.min = arr[i];
            }
        }

        i += 2;
    }

    return MinMax;
};

int main() {
    int arr[6] = {1, 5, 4, 30, 2, 0};
    int n = sizeof(arr)/sizeof(int);

    Pair ans = getMinMax(arr, n);

    cout<<ans.max<<"    "<<ans.min;

    return 0;
}
