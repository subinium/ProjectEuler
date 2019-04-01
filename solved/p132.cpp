#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll SZ = 1e9;

ll cnt = 40, ans;

ll power(ll a, ll b, ll mod){
  ll res = 1;
  while(b){
    if(b&1) res = res*a%mod;
    a = a*a % mod;
    b >>= 1;
  }
  return res;
}

bool pck(ll n){
  for(ll i = 2; i*i <= n ; i++) if(n%i==0) return false;
  return true;
}

int main(){
  for(ll i = 3 ; cnt ; i+=2){
    if(!pck(i)) continue;
    if(power(10,SZ,9*i)==1){
      ans += i;
      cnt--;
    }
  }
  cout << ans;
}
