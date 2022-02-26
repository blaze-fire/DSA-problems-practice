// give number of ways in which a target string can be achiebed by concatenating substringd from given array
#include<iostream>
#include<vector>
using namespace std;

void canConstruct(string target, vector<string> wordBank){
    vector <int> table;  
    for(int i=0; i<target.size()+1;i++){
        table.push_back(0);
    }
    table[0] = 1;
    for(int i=0; i <= target.size(); i++){
        for(int j=0; j<wordBank.size(); j++){
            if(target.compare(i, i+wordBank[j].size(), wordBank[j]) == 0){
                table[i+wordBank[j].size()] += table[i];
            }
        }
    }
    cout<<table[target.size()];

}

int main(){
    vector<string> arr = {"purp","p","ur","le","purp"};
    //vector<string> arr = {"bo","rd","ate","t","ska","sk","boar"};
    string target = "purple";
    //string target = "skateboard";
    canConstruct(target,arr);
    return 0;
}