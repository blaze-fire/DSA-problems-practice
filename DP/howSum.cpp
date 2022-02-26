//given a target and an array print all the combinations from array that sum to target

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> local;

void CanSum(int l, int target, vector<int> arr, map<vector<int>, bool> &memo){
    if(memo[local])  return;
    if(target < 0)    return;
    if(target == 0){
        for(int i=0; i < local.size(); i++){
            cout<<local.at(i)<<"    ";
        }
        memo[local] = true;
        cout<<endl;
        return;
    }

    for(int i=l; i<arr.size(); i++){
        int remainder = target - arr.at(i);
        local.push_back(arr[i]);
        CanSum(i+1, remainder, arr, memo);
        local.pop_back();
    }

    return;
}

int main() {
    map <vector<int>, bool> memo;
    vector<int> arr = {2, 5, 4, 3, 1};
    CanSum(0, 7, arr, memo);
}
