#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int sz = 1e8+5;
int arr[sz];

int main(){
  int ck;
  for(int i = 2 ; i < sz ; i++ ){
    if(arr[i]) continue;
    for(int j = i*2 ; j < sz ; j+=i){
      arr[j] = 1;
    }
  }
  long long ans = 0;
  for(int i = 1 ; i <= 100000000; i++){
    int ck = 1;
    //printf("%d\n",i);
    for(int j = 1 ; j*j<= i ; j++){
      if(!ck) break;
      if(i%j==0){
        int tmp = j + (i/j);
        if(arr[tmp]==1){
          //cout << i << ' ' << tmp << endl;
          ck = 0;
          break;
        }
      }
    }
    if(ck){
      //printf("%d\n",i);
      ans += (long long)i;
    }
  }
  cout << ans;
}
