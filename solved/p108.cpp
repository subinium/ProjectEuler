#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1e7;

int arr[SZ];

void era(){
  for(int i = 1 ; i < SZ ; i++) arr[i] = 1;
  for(int i = 2 ; i < SZ ; i++){
    if(arr[i]!=1) continue;
    for(int j = i ; j < SZ ; j += i){
      int cnt = 0;
      int tmp = j;
      while(tmp % i == 0){
        cnt++;
        tmp /= i;
      }
      arr[j] *= cnt*2+1;
    }
  }
}

int main(){
  era();
  for(int i = 1000 ; ; i++){
    if((arr[i]+1)/2>1000){
      cout << i << endl;
      return 0;
    }
  }
}
