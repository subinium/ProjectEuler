#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll SZ = 1e8;
const ll MOD = 1e9+9;

ll ans = 1;

bool arr[SZ+1];

ll power(ll a, ll b, ll mod){
  ll ret = 1;
  while(b){
    if(b&1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

void era(){
  for(ll i = 2 ; i <= SZ ; i++){
    if(arr[i]) continue;
    ll cnt = 0;
    ll m = SZ;
    while(m){
      cnt += m/i;
      m /= i;
    }
    ans = ans * (power(i, cnt*2, MOD) + 1) % MOD;
    for(ll j = i*i ; j <= SZ ; j+= i){
      arr[j] = true;
    }
  }
}

int main(){
  era();
  cout << ans;
}
