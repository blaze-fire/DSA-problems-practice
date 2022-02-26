// canconstruct problem but now using tabulation
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canConstruct(string target, vector<string> wordbank){
    bool table[target.size() + 1] = {false};
    for (int i=0; i<= target.size(); i++){
        for(int j=0; j<wordbank.size(); j++){
        // if the word matches the characters starting at position i
            if(target.compare(i, i + wordbank[j].size(), wordbank[j]) == 0){
                
                // jump on the basis of length of substring choosing
                    table[i+wordbank[j].size()] = true;                             
            
            }
        }
    
    }
    return table[target.size()];
}

int main(){
    vector<string> wordbank = {"ab","abc","cd","def","abcd"};
    string target = "abcdef";
    if(canConstruct(target, wordbank)){
        cout<<endl<<"Yes !!";
    }
    else{
        cout<<endl<<"No !!";
    }
    return 0;
}