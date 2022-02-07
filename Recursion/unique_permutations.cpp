#include <bits/stdc++.h>
using namespace std;


void permutaions(char *in, int i, set<string> &st){
    if(in[i] == '\0'){
        //cout<<in<<endl;
        string temp_str(in);

        st.insert(temp_str);

        return;
    }

    for(int j=i; in[j] != '\0'; j++){
        swap(in[i], in[j]);
        permutaions(in, i+1, st);
        swap(in[i], in[j]);
    }


}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    char in[50];
    cin>>in;

    set<string> st; 
    permutaions(in, 0, st);

    for(auto itr : st){
        cout<<itr<<"    ";
    }

    return 0;
}
