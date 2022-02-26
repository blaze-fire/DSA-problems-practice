#include <bits/stdc++.h>
using namespace std;


void permutaions(char *in, int i){
    if(in[i] == '\0'){
        cout<<in<<endl;
        return;
    }

    for(int j=i; in[j] != '\0'; j++){
        swap(in[i], in[j]);
        permutaions(in, i+1);
        //Backtracting to restore the orignal array
        swap(in[i], in[j]);
    }


}


int main() {
    char in[50];
    cin>>in;

    permutaions(in, 0);

    return 0;
}
