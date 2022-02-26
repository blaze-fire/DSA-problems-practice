/*Generate all binary strings without consecutive 1’s*/


#include<bits/stdc++.h>
using namespace std;


void PrintBinary(char str[], int n, int index){
    if(index == n){
        str[n] = '\0';
        cout << str << endl;
        return;
    }

    if(str[index-1] == '1'){
        str[index] = '0';
        PrintBinary(str, n, index+1);
    }

    if(str[index-1] == '0'){
        str[index] = '1';
        PrintBinary(str, n, index+1);


        str[index] = '0';
        PrintBinary(str, n, index+1);
    }
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    char str[n];

    str[0] = '0';
    PrintBinary(str, n, 1);


    str[0] = '1';
    PrintBinary(str, n, 1);

    return 0;
}