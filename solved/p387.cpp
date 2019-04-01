#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e14;
const int SZ = 1e7;

ll ans;
bool arr[SZ];
vector<ll> v;

void era(){
  for(ll i = 2 ; i < SZ ; i++){
    if(arr[i]) continue;
    v.push_back(i);
    for(ll j = i*i ; j < SZ ; j+=i){
      arr[j] = true;
    }
  }
}

bool p(ll n){
  if(n==1) return false;
  for(int i = 0 ; v[i]*v[i] <= n ; i++){
    if(n%v[i]==0) return false;
  }
  return true;
}

void dfs(ll n, ll sum){
  if(n*10>=INF) return ;
  for(ll i = 0 ; i < 10 ; i++){
    if((n*10+i)%(sum+i)==0){
      dfs(n*10+i,sum+i);
    }
    if(p(n*10+i)&&p(n/sum)){
      ans += n*10+i;
      //cout << n*10+i << endl;
    }
  }
}

int main(){
  era();
  for(ll i = 1 ; i <= 9 ; i++){
    dfs(i,i);
  }
  cout << ans;
}
