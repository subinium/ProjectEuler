#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MX = 1e12;
const ll SZ = 1e6;

ll ans;

int main(){
  set<ll> ck, tot;
  for(ll i = 2 ; i <= SZ ; i++){
    ll f = i*i+i+1;
    for(; f < MX ; f = f*i+1){
      if(tot.count(f)) continue;
      else tot.insert(f);
      ans += f;
      
    }  
  }
  cout << ans+1;
}
