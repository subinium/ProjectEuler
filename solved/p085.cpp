#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> v;

int sz = 2e6;

int main(){
  v.push_back(0);
  for(int i = 1 ; v[i-1] < 2*sz ; i++){
    v.push_back(v[i-1]+i-1);
  }
  int ans = -1;
  int nearest = 0;
  for(int i = 2 ; i < v.size() ; i++){
    int tsz = sz/v[i];
    int k = upper_bound(v.begin(),v.end(),tsz)-v.begin();
    int down = k-1;
    if(abs(sz-nearest)>abs(sz-v[i]*v[k])){
      ans = (i-1)*(k-1);
      nearest = v[i]*v[k];
    }
    if(abs(sz-nearest)>abs(sz-v[i]*v[down])){
      ans = (i-1)*(down-1);
      nearest = v[i]*v[down];
    }
  }
  cout << nearest << endl;
  cout << ans;
}
