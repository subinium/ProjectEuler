#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string mx = "";
int ck_bit = (1<<9)-1;

string itos(int n){
  string ret = "";
  while(n){
    ret = (char)(n%10+'0') + ret;
    n /= 10;
  }
  return ret;
}

void process(int n){
  int ans = 0;
  for(int i = 1 ; ; i++){
    int tmp = n*i;
    while(tmp){
      int k = tmp%10;
      if(k==0) return;
      if(ans & (1<<(k-1))) return;
      ans |= 1<<(k-1);
      tmp /= 10;
    }
    if(ans==ck_bit){
      string res = "";
      for(int j = 1 ; j <= i ; j++) res += itos(n*j);
      mx = max(mx,res);
      return ;
    }
  }
}


int main(){
  for(int i = 1 ; i < 10000 ; i++){
    process(i);
  }
  cout << mx;
}
