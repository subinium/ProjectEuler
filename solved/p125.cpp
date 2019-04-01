#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e8;

bool isPalin(ll n){
  ll m = n, rev = 0;
  while(m){
    rev = 10*rev + m%10;
    m /= 10;
  }
  return n == rev;
}

ll sq(ll a){return a*a;}

int main(){
  set<ll> st;
  for(ll i = 1; 2*i*i < SZ ; i++){
    ll nxt = i+1;
    ll tot = sq(st) + sq(nxt)
    while(tot < SZ){
      if(isPalin(tot)) st.push_back(tot);
      nxt++;
      tot += sq(nxt);
    }
  }
  ll sum = 0;
  for(auto i : st) sum += i;
  cout << sum;
}
