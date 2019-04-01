#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll pow(ll a, ll b, ll mod){
  ll ret = 1;
  while(b){
    if(b&1){
      ret *= a;
      ret %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ret;
}

int main(){
  ll ans = 0;
  for(ll i = 3 ; i <= 1000 ; i++){
    ll mx = 0;
    for(ll j = 1; j <= 2*i ; j++){
      mx = max(mx, (pow(i-1,j,i*i)+pow(i+1,j,i*i))%(i*i));
    }
    ans += mx;
  }
  cout << ans;
}
