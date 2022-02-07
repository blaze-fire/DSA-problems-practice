// given a target and an array print all the combinations from array that sum to target using tabulation

#include <iostream>
#include <vector>

using namespace std;

vector<int> HowSum(int targetsum, vector<int> arr){

    vector<vector<int>> table;                    // vector table store the combination  

    for(int i=0; i <= targetsum; i++){
        table.push_back({});
    }
  
    table[0].push_back(0);
  
  for(int i=0; i<=targetsum; i++){
        for(int j=0; j<arr.size(); j++){
            if(!table[i].empty()){
                
              if(i + arr.at(j) == targetsum){
                    table[i + arr.at(j)].push_back(arr.at(j));
                    table[i + arr.at(j)].push_back(i);
                    return table[targetsum];
                }

                if(i + arr.at(j) <= targetsum)
                    table[i + arr.at(j)].push_back(arr.at(j));
            }
        }
    }

    return table[targetsum];
}

int main() {
    vector<int> arr = {6, 3, 3, 12, 9,4,4};
    vector<int> ans = HowSum(7, arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans.at(i)<<"  ,   ";
    }
    return 0;
}
