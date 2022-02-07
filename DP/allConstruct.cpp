//given a target and an array of strings print all the combinations from array elements that sum to target

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> local;
vector<string> ans;                                               // to store the shortest combination

void canConstruct(int l, string &target, vector <string> &arr, string target_copy){
  if(target.size() == 0){
      for(int i=0; i<local.size(); i++){
          ans.push_back(local.at(i));
      }
      target = target_copy;                                         // set again to target_copy to get all combinations
  }

  for(int i=l; i<arr.size(); i++ ){
    
    int remainder = target.compare(0,arr[i].size(),arr[i]);         // will return 0 if match 
    if(remainder == 0){ 
        target.erase(0,arr[i].size());                              // Erase the substring from target that match from array 
        local.push_back(arr[i]);
        canConstruct(i+1,target, arr, target_copy);
        local.pop_back();
    }
  
  }

}

int main(){
  vector <string> arr = {"abc", "fgh","ab","cdef", "def"};
  string target = "abcdef",target_copy;
  target_copy = target;                                             // to maintain a copy to restore target string 
  
  canConstruct(0,target,arr,target_copy);
  vector<string>::iterator itr = ans.begin();

  for(; itr != ans.end(); itr++){
    cout<<*itr<<"   ";
  }
  return 0;
}