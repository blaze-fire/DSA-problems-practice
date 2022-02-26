/*
This problem was asked by Epic.

The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.

*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string str="1";
    cout<<"1"<<endl;
    n--;
    while(n--){
        int count = 0;
        string temp_str="";
        int digit = -1;
        for(int i=str.size()-1; i>=0; i--){
            if(count > 0 and digit != str[i]-'0' and digit != -1){
               temp_str += to_string(digit*10 + count);
               count = 0;
            }
            digit = str[i] - '0';
            count++;
        }
        
        if(count != 0){
            temp_str += to_string(digit*10 + count);
        }
        reverse(temp_str.begin(), temp_str.end());
        cout<<temp_str<<endl;
        str = temp_str;
    }
}
