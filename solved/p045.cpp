#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<ll, int> mp;

ll tri(ll n){return n*(n+1)/2;}
ll penta(ll n){return n*(3*n-1)/2;}
ll hex(ll n){return n*(2*n-1);}

int main(){
  for(ll i = 1 ; tri(i) < 1e12 ; i++) mp[tri(i)]++;
  for(ll i = 1 ; penta(i) < 1e12 ; i++) mp[penta(i)]++;
  for(ll i = 1 ; hex(i) < 1e12 ; i++){
    if(mp[hex(i)]==2) cout << hex(i) << '\n';
  }
}
