#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 12;

int comb(int n, int r){
  int ret = 1;
  for(int i = 0 ; i < r ; i++){
    ret = ret * (n-i) / (i+1);
  }
  return ret;
}

int catalan(int n){
  return comb(2*n,n)/(n+1);
}

int main(){
  int ans = 0;
  for(int i = 2 ; i*2 <= SZ ; i++){
    ans += comb(SZ,i) * comb(SZ-i,i) / 2;
    ans -= comb(SZ,2*i) * catalan(i) ;
  }
  cout << ans;
}
