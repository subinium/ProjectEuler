#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 500500507;
const int sz = 6e7;

priority_queue<ll, vector<ll>, greater<ll> > pq;

bool pr[sz];

void era(){
  for(int i = 2 ; i < sz ; i++){
    if(pr[i]) continue;
    pq.push(i);
    for(int j = 2*i ; j < sz ; j+=i){
      pr[j] = true;
    }
  }
}

int main(){
  era();
  ll ans = 1;
  for(int i = 0 ; i < 500500 ; i++){
    ll tp = pq.top(); pq.pop();
    ans *= tp;
    pq.push(tp*tp);
    ans %= MOD;
    //cout << ans << '\n';
  }
  cout << pq.top() << endl;
  cout << ans;
}
