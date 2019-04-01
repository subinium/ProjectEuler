#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b){ return a%b?gcd(b,a%b):b;}
ll lcm(ll a, ll b){ return a/gcd(a,b)*b;}

ll P(ll s, ll N){
  ll d = 1;
  for(ll i = 2 ; i <= s ; i++){
    d = lcm(d,i);
  }
  ll dd = lcm(d,s+1);
  N -= 2;
  return N/d - N/dd;
}

int main(){
  cout << P(6,1000000) << endl;
  ll ans = 0;
  ll sz = 31, flag = 4;
  for(ll i = 1 ; i <= sz ; i++){
    ans += P(i,flag);
    flag *= 4;
  }
  cout << ans;
}
