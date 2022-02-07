//given a target and an array print the shortest length of combination from array that sum to target
//given a target and an array print all the combinations from array that sum to target

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> local;
int smallest = 10000;

// here size of array os key and the vector is value

void CanSum(int l, int target, vector<int> arr, map<int, vector<int>> &memo){
    if(memo.find(local.size()) != memo.end())  return;                        // if already an array of that size exists no need to proceed 
    if(target < 0)    return;
    if(target == 0){
        if(local.size()<smallest){                                            // if given array is smallest replace the smallest array
            smallest = local.size();
            memo[smallest] = local;
        }
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
    map <int, vector<int>> memo;
    vector<int> arr = {2, 5, 4, 3, 1, 7};
    CanSum(0, 7, arr, memo);
    auto itr = memo[smallest].begin();
    for(; itr != memo[smallest].end(); itr++){
        cout<<*itr<<"   ";
    }

    return 0;
}
