#include <iostream>
#include <unordered_map>
using namespace std;
double fib(int n, unordered_map<int,double> &memo){
  if(memo.count(n) >0) return memo[n];
  if(n<=2)  return 1;
  memo[n] = fib(n-1,memo) + fib(n-2,memo);
  
  return memo[n];
}
int main() {
  unordered_map <int,double> memo;
  std::cout<<fib(4,memo)<<endl;
  std::cout<<fib(6,memo)<<endl;

  std::cout<<fib(50,memo);
}