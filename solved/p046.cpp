#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int sz = 1e7;

int p[sz];

int main(){
  for(int i = 2 ; i < sz ; i++){
    if(p[i]) continue;
    for(int j = 2*i ; j < sz ; j+= i){
      p[j] = 1;
    }
  }
  for(int i = 3 ; i < sz ; i+=2){
    if(p[i]==1){
      cout << i << endl;
      return 0;
    }
    if(p[i]==2) continue;
    for(int j = 1 ; i+2*j*j < sz ; j++){
      if(p[i+2*j*j]) p[i+2*j*j] = 2;
      //cout << i+2*j*j << endl;
    }
  }
}
