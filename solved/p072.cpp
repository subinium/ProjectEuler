#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll sz = 1e6;

ll f(ll n){
  vector<ll> v;
  ll ret = n;
  ll flag = 2;
  while(n>=flag*flag){
    if(n%flag==0){
      v.push_back(flag);
      while(n%flag==0){
        n/=flag;
      }
    }
    else flag++;
  }
  if(n!=1) v.push_back(n);
  for(int i = 0 ; i < v.size() ; i++){
    ret /= v[i];
    ret *= v[i]-1;
  }
  return ret;
}

int main(){
  ll ans = 0;
  for(int i = 2 ; i <= sz ; i++){
    //cout << i << ' ' << f(i) << endl;
    ans += f(i);
  }
  cout << ans;
}
