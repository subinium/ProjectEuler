#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int si(string s){
  int res = 0;
  for(int i = 0 ; i < s.size() ; i++){
    res = res*10 + s[i]-'0';
  }
  return res;
}

bool prime(int n){
  for(int i = 2 ; i*i <= n ; i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  // 9 and 8's digit total is 45 , 36 and it means num always divied by 3
  string a = "7654321";
  do{
    //cout << a << endl;
    if(prime(si(a))){
      cout << a;
      break;
    }
  }while(prev_permutation(a.begin(),a.end()));
}
