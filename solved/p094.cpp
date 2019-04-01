#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll SZ = 1e9;

ll sq(ll a){ return a*a; }

ll f(ll n){
  ll lo = 1, hi = SZ;
  while(lo <= hi){
    ll mid = (lo+hi)>>1;
    if(mid*mid==n) return mid;
    if(mid*mid>n) hi = mid-1;
    else lo = mid+1;
  }
  return 0;
}

int main(){
  ll ans = 0;
  for(ll i = 3 ; 3*i+2 <= SZ ; i++){
    ll a = f(sq(2*i+2) - sq(i));
    ll b = f(sq(2*i-2) - sq(i));
    //cout << sq(2*i-2)-sq(i) <<endl;
    if(a&&a*i%4 == 0){
      ans+= 3*i+2;
    }
    if(b&&b*i%4 == 0){
      ans+= 3*i-2;
    }
  }
  cout << ans;
}

// 2m 7s
