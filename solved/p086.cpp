#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1e6;

map<ll, bool> mp;

ll sq(ll a){
  return a*a;
}

bool tri(ll a, ll b, ll c){
  return mp[sq(a)+sq(b+c)];
}

int main(){
  for(ll i = 1 ; i <= 5*MX ; i++) mp[i*i] = true;
  int ans = 0;
  for(int i = 1 ; ; i++){
    for(int j = 1 ; j < i ; j++){
      if(tri(i,i,j)) ans ++;
      for(int k = 1 ; k <= j ; k++){
        if(tri(i,j,k)) ans ++;
      }
    }
    if(ans > MX){
      cout << i << ' ' << ans;
      return 0;
    }
  }
}

// 8m 4s
