#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int sz = 1e6;
const int MAX = 1e6;

vector<int> v;
int p[sz];
int ans;

int main(){
  for(int i = 2 ; i < sz ; i++){
    if(p[i]) continue;
    v.push_back(i);
    for(int j = 2*i ; j < sz ; j+=i){
      p[j] = 1;
    }
  }
  int mcnt = 0;
  for(int i = 0 ; i < v.size() ; i++){
    int flag = i;
    int sum = 0;
    
    while(sum < sz&&flag<v.size()){
      if(sum&&!p[sum]&&mcnt<=flag-i) ans = sum, mcnt = flag-i; 
      sum += v[flag++];
    }
  }
  cout << ans;

}
