#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll N = 2e7;
const ll M = 5e6;

vector<ll> pr;
bool arr[N];

void era(){
  for(int i = 2; i < N; i++){
    if(arr[i]) continue;
    pr.push_back(i);
    for(int j = 2*i ; j < N ; j+=i){
      arr[j] = true;
    }
  }
}

ll pcnt(ll a, ll p){
  ll ret = 0;
  while(a){
    ret += a/p;
    a/= p;
  }
  return ret;
}

int main(){
  era();
  ll ans = 0;
  for(int i = 0 ; i < pr.size() ; i++){
    ans += pr[i] * (pcnt(N,pr[i])-pcnt(M,pr[i])-pcnt(N-M,pr[i]));
  }
  cout << ans;

}
