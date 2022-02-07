// Used memoization to store values already computed to save time calculating them again
// Time Complexity O(m*n) Space Complexity( O(m) )

#include <iostream>
#include <map>

using namespace std;

typedef pair<int,int> Pair; 

double GridTraveller(int m, int n, map <Pair,double> &memo){
  Pair key = make_pair(m,n);

  if(memo.count(key)>0) return memo[key];
  if(m==1 && n==1)  return 1;
  if(m==0 || n==0) return 0;

  memo[key] = GridTraveller(m-1,n,memo) + GridTraveller(m,n-1,memo);      //store the values inside map so not to calculate them again and again saving time
  return memo[key];
}

int main(){
    map <Pair,double> memo;                                        //memoization

    cout<<GridTraveller(1,1,memo)<<endl;
    cout<<GridTraveller(2,2,memo)<<endl;
    cout<<GridTraveller(2,3,memo)<<endl;
    cout<<GridTraveller(3,3,memo)<<endl;
    cout<<GridTraveller(20,20,memo)<<endl;
    return 0;
}