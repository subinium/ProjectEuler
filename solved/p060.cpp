#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e8;
const int sz = 1e4;
const int CNT = 5;

int arr[SZ];
vector<ll> p;
vector<ll> edge[sz];
int ck[sz][sz];

ll ans = 1e9;

void era(){
  for(ll i = 2 ; i < SZ ; i++){
    if(arr[i]) continue;
    if(i%2&&i%10!=5&&i<sz)p.push_back(i);
    for(ll j = i*i ; j < SZ ; j+=i){
      arr[j] = 1;
    }
  }
}

ll len10(ll n){
  ll ret = 1;
  for(;ret<=n ; ret*=10);
  return ret;
}

bool connect(ll a, ll b){
  ll la = len10(a), lb = len10(b);
  return !arr[la*b+a]&&!arr[lb*a+b];
}

void dfs(int idx, vector<ll> v){
  if(v.size()==CNT){
    ll tot = 0;
    for(int i = 0 ; i < CNT ; i++){
      tot += p[v[i]];
      //cout << p[i] << ' ';
    }
    cout << tot << endl;
    cout << endl;
    ans = min(ans,tot);
    return ;
  }
  //cout << idx << endl;
  for(int i = 0 ; i < edge[idx].size() ; i++){
    if(edge[idx][i] < idx) continue;
    bool flag = true;
    for(int j = 0 ; j < v.size() ; j++){
      if(ck[edge[idx][i]][v[j]]==0){
        flag = false;
        break;
      } 
    }
    if(flag){
      v.push_back(edge[idx][i]);
      dfs(edge[idx][i],v);
      v.pop_back();
    }
  }
}

int main(){
  era();
  int pcnt = p.size();
  for(int i = 0 ; i < pcnt ; i++){
    for(int j = i+1 ; j < pcnt ; j++){
      if(connect(p[i],p[j])){
        edge[i].push_back(j);
        edge[j].push_back(i);
        ck[i][j] = ck[j][i] = 1;
      }
    }
  }
  for(int i = 0 ; i < pcnt ; i++){
    vector<ll> s; s.push_back(i);
    dfs(i, s);
  }
  cout << ans;
}
