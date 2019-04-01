#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dp[1000001];
ll pr[1000001];
void pro(){
  for(int i = 1 ; i <= 1000000 ; i++) dp[i] = i;
  for(int i = 2 ; i <= 1000000 ; i++){
    if(pr[i]) continue;
    for(int j = i ; j <= 1000000 ; j+= i){
      dp[j] = dp[j] / i * (i-1);
      pr[j] = 1;
    }
  }
}

int main(){
  pro();
  ll m = 1, s = 1, f = 1;
  for(ll i = 2 ; i <= 1000000 ; i++){
    ll t = dp[i];
    if(s*t<i*m){
      f = i;
      m = t;
      s = i;
    }
  }
  cout << f <<endl;
}
