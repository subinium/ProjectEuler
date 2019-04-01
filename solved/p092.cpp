#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int d(int n){
  int ret = 0;
  while(n){
    ret += (n%10)*(n%10);
    n /= 10;
  }
  return ret;
}

int s(int x){
  while(x!=1&&x!=89){
    x = d(x);
  }
  return x;
}

int main(){
  int ans = 0;
  for(int i = 1 ; i < 10000000 ; i++){
    if(s(i)==89) ans++;
  }
  cout << ans;
}
