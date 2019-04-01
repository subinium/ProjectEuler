#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int sz =  1e7+1;

int arr[sz];
vector<int> v[sz];
set<pii> s;

void era(){
  for(int i = 2 ; i < sz; i++){
    if(arr[i]) continue;
    for(int j = 2*i ; j < sz ; j+= i){
      arr[j] ++;
      v[j].push_back(i);
    }
  }
}

int main(){
  era();
  ll ans = 0;
  for(int i = sz-1 ; i > 0 ; i--){
    if(arr[i]==2 && s.count(pii(v[i][0],v[i][1]))==0){
      ans += (ll)i;
      s.insert(pii(v[i][0],v[i][1]));
    }
  }
  cout << ans;
}
