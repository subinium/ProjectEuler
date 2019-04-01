#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll ANS_MOD = 1e16;
const ll MOD = 250;
const int SZ = 250250;

ll DP[SZ+1][MOD];
ll arr[SZ+1];

ll power(ll a, ll b, ll mod){
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
  DP[0][0] = 1;
  for(ll i = 1 ; i <= SZ ; i++) arr[i] = power(i,i,MOD);
  for(int i = 1 ; i <= SZ ; i++){
    for(int j = 0 ; j < MOD ; j++){
      int NXT = (j + arr[i]) % MOD;
      DP[i][NXT] += DP[i-1][j] + DP[i-1][NXT];
      DP[i][NXT] %= ANS_MOD;
    }
  }
  cout << DP[SZ][0] - 1;
}
