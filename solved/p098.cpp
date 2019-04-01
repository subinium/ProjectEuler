#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> P;
const int SZ = 2000;
const ll MX = 1e10;

string s;

vector<string> v;
vector<ll> len[14];
map<ll, int> mp;

void init(){
  cin >> s;
  int ck = 0;
  string tmp;
  for(int i = 0 ; i < s.size() ; i++){
    if(s[i]=='\"'){
      if(!ck) tmp = "";
      else v.push_back(tmp);
      ck ^= 1;
    }
    else tmp += s[i];
  }
}

void process(){
  ll flag = 10, idx = 1;
  for(ll i = 1 ; i*i < MX ; i++){
    if(i*i >= flag ) flag *= 10, idx++;
    len[idx].push_back(i*i);
    mp[i*i] = 1;
  }
}

bool same(string a, string b){
  if(a.size()!=b.size()) return false;
  sort(a.begin(),a.end()); sort(b.begin(),b.end());
  return a == b;
}

int main(){
  freopen("p098_words.txt","r",stdin);
  init();
  process();
  ll ans = 0;
  for(int i = 0 ; i < v.size() ; i++){
    for(int j = i+1 ; j < v.size() ; j++){
      if(same(v[i],v[j])){
        int sz = v[i].size();
        for(int k = 0; k < len[sz].size() ; k++){
          ll tmp = len[sz][k];
          bool ck = true;
          int F[128], used[10];
          memset(F,-1,sizeof(F));
          memset(used,-1,sizeof(used));
          for(int x = 0 ; x < sz ; x++){
            if(F[v[i][sz-x-1]]==-1){
              if(used[tmp%10]==-1){
                F[v[i][sz-x-1]] = tmp%10;
                used[tmp%10] = v[i][sz-x-1];
              }
              else{
                ck = false;
                break;
              }
            }
            else{
              if(F[v[i][sz-x-1]] != tmp%10){
                ck = false;
                break;
              }
            }
            tmp /= 10;
          }
          tmp = 0;
          for(int x = 0 ; x < sz ; x++){
              if(F[v[j][x]]!=-1) tmp = tmp*10 + F[v[j][x]];
              else ck = false;
          }
          if(ck&&mp[tmp]&&F[v[j][0]]!=0){
            ans = max(ans, tmp);
            ans = max(ans, len[sz][k]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
