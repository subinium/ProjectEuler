#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int ans = -1;
  int flag = 0;
  for(int i = 1 ; i <= 1000 ; i++){
    int tmp = 0;
    for(int j = 1 ; j <= i ; j++){
      for(int k = j ; j+k <= i ; k++){
        int q = i-j-k;
        if(q<k) break;
        if(j*j+k*k==q*q){
          tmp++;
        }
      }
    }
    if(tmp>ans){
      flag = i;
      ans = tmp;
    }
  }
  cout << flag << ' ' << ans;
}
