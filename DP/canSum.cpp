// given a targetsum and an array return a bollean value whether it is possible to
// generate target sum using given array

#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> ans;
typedef pair<int,int> Pair; 

bool canSum(int l, int target, vector <int> &arr, map<int,bool> &memo){
  if(memo.count(target) > 0) return memo[target];
  if(target == 0) return true;
  if(target < 0 ) return false;

  for(int i=l; i<arr.size(); i++ ){
    int remainder = target - arr[i];                //get value and increment at the same time
  
    if(canSum(i+1,remainder, arr, memo)){
      cout<<arr[i]<<" ";                            // to print the desired numbers that reach the targetsum
      memo[target] = true;
      return true;
    }  
  }
  memo[target] = false;
  return false;
}

int main(){
  vector <int> arr = {4, 1, 2, 3};
  map <int,bool> memo;
  if(canSum(0,7,arr,memo)){
    cout<<endl<<"Yes !!"<<endl;
  }    
  else
  {
    cout<<endl<<"No"<<endl;
  }
    return 0;
}