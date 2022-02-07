// same problem of allConstruct using tabulation
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void allConstruct(string target, vector <string> wordBank){
    unordered_map <int, vector<string>> table;
    for(int i=0; i<=target.size(); i++){
        for(int j=0; j<wordBank.size(); j++){
            if(target.compare(i, i+wordBank[j].size(), wordBank[j]) == 0){
               // cout<<wordBank.at(j)<<"     ";
                table[i+wordBank[j].size()].push_back(wordBank.at(j));      
            }
        }
    }
    auto itr = table[target.size()].begin();
    for(; itr != table[target.size()].end(); itr++){
       cout<<*itr<<"           ";
    }
}

int main(){
    vector<string> arr = {"purp","p","ur","le","purpl","le"};
    string target = "purple";
    allConstruct(target, arr); 
    return 0;
}