//given a target and an array of strings print the array elements from array that sum to target

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ans;                          // to store the shortest combination

void canConstruct(int l, string &target, vector <string> &arr){
  if(target.size() == 0)  return;

  for(int i=l; i<arr.size(); i++ ){
    
    int remainder = target.compare(0,arr[i].size(),arr[i]);         // will return 0 if match 
    if(remainder == 0){ 
        target.erase(0,arr[i].size());                              // Erase the substring from target that match from array 
        ans.push_back(arr[i]);
        canConstruct(i+1,target, arr);
    }
  
  }

}

int main(){
  vector <string> arr = {"abc", "fgh","","", "def"};
  string target = "abcdef";
  canConstruct(0,target,arr);
  vector<string>::iterator itr = ans.begin();

  for(; itr != ans.end(); itr++){
    cout<<*itr<<"   ";
  }
  return 0;
}