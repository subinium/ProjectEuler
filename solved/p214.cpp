#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 40000000;
const int CHAIN_LEN = 25;

int dp[SZ];
ll phi[SZ];

void era_totient(){
  for(ll i = 1 ; i < SZ ; i++) phi[i] = i;
  for(ll i = 2 ; i < SZ ; i++){
    if(phi[i] != i) continue;
    for(ll j = i ; j < SZ ; j+=i){
      phi[j] = phi[j]/i*(i-1);
    }
  }
}

int main(){
  era_totient();
  dp[1] = 1;
  ll ans = 0;
  for(int i = 2 ; i < SZ ; i++){
    dp[i] = dp[phi[i]] + 1;
    if(dp[i]==CHAIN_LEN && phi[i]==i-1) ans += (ll) i;
  }
  cout << ans;
}
