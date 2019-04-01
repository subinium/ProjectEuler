#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> P;
const int SZ = 40;
#define fi first
#define se second

int rt[SZ], ans;
vector<P> v;

void init(){
  for(int i = 0 ; i < SZ ; i++) rt[i] = i;
  for(int i = 0 ; i < SZ ; i++){
    string s; cin >> s;
    int idx = 0, val = 0;
    for(int j = 0 ; j < s.size() ; j++){
      if(s[j]=='-') continue;
      if(s[j]==',' ){
        if(val) v.push_back(P(val,pii(i,idx)));
        ans += val;
        idx++; val = 0;

      }
      else{
        val = val * 10 + s[j]-'0';
      }
    }
    if(val) v.push_back(P(val, pii(i,idx)));
    ans += val;
  }
  ans /= 2;
}

int find(int x){
  if(rt[x] == x) return x;
  return rt[x] = find(rt[x]);
}

int main(){
  freopen("p107_network.txt","r",stdin);
  sort(v.begin(), v.end());
  for(int i = 0 ; i < v.size() ; i++){
    int x = v[i].se.fi, y = v[i].se.se;
    int xx = find(x), yy = find(y);
    if(xx==yy) continue;
    rt[xx] = rt[yy];
    ans -= v[i].fi;
  }
  cout << ans;
}
