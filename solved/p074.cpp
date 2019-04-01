#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e6;

int fac[10] = {1};

int nxt(int n){
  int ret = 0;
  while(n){
    ret += fac[n%10];
    n /= 10;
  }
  return ret;
}

int cycle(int n){
  set<int> s;
  for(int i = 1 ; i <= 61 ; i++){
    s.insert(n);
    n = nxt(n);
  }
  return s.size();
}

int main(){
  for(int i = 1 ; i < 10 ; i++) fac[i] = fac[i-1]*i;
  int ans = 0;
  for(int i = 1 ; i <= SZ ; i++){
    ans += cycle(i)==60;
  }
  cout << ans;

}
