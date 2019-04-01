#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll sz = 1e9;

int ans;

int main(){
  for(ll i = 1 ; i < sz ; i++){
    if(i%10==0) continue;
    ll j = i, rev = 0;
    while(j){
      rev = rev*10 + j%10;
      j /= 10;
    }
    rev += i;
    while(rev){
      if(rev%2==0) break;
      rev /= 10;
    }
    if(rev==0) ans ++;
  }
  cout << ans;
}
