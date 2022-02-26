#include <iostream>
using namespace std;
    
int fib(int size){
    int table[size];
    for(int i=0; i<size; i++){
        table[i] = 0;
    }
        
    table[1] = 1;
    
    for(int i=1; i<size; i++){
        if(i+2<size){
            table[i+1] += table[i];
            table[i+2] += table[i];
        }
        else if(i == size-2){
            table[i+1] += table[i];
        }
    }
    
    return table[size-1];
    
}

int main() {
    int n = 6;
    cout<<fib(n+1)<<endl;
}