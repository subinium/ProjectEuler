#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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

const int sz = 1e8;

int arr[sz];

void era(){
  for(ll i = 2 ; i < sz ; i++){
    if(arr[i]) continue;
    for(ll j = i*i ; j < sz ; j +=i){
      arr[j] = 1;
    }
  }
}

ll process(ll p){
  ll ret = p-1;
  ll flag = p-1;
  for(ll i = 1 ; i <= 4 ; i++){
    flag *= power(p-i,p-2,p);
    flag %= p;
    ret += flag;
    ret %= p;
  }
  return ret ;
}

int main(){
  era();
  ll ans = 0;
  for(ll i = 5 ; i < sz ; i++){
    if(arr[i]) continue;
    ans += process(i);
  }
  cout << ans;
}
