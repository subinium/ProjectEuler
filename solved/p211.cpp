#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 8000*8000;
ll s[SZ+1];

bool isPerfectSquare(long double x){  
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}

int main(){
  ll ans = 0;
  for(ll i = 1 ; i <= SZ ; i++){
    for(ll j = i ; j <= SZ ; j+=i){
      s[j] += i*i;
    }
    ans += i*isPerfectSquare(s[i]);
  }
  cout << ans;
    
}

// 14s
