#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<int, bool> mp;

int pn(int idx){
  return idx*(3*idx-1)/2;
}

int main(){
  int ans = 2e9;
  for(int i = 1 ; i <= 10000 ; i++) mp[pn(i)] = true;
  for(int i = 1 ; i <= 10000 ; i++){
    for(int j = i+1 ; j <= 10000 ; j++){
      if(mp[pn(i)+pn(j)]&&mp[pn(j)-pn(i)]){
        ans = min(ans,pn(j)-pn(i));
      }
    }
  }
  cout << ans;
}

// 1m 19s
