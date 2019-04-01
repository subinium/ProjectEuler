#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int vector_sum(vector<int> v){
  int ret = 0;
  for(auto i : v) ret += i;
  return ret;
}

int bit_cnt(int n){
  int ret = 0;
  while(n){
    ret += n&1;
    n /=2;
  }
  return ret;
}

bool ans_check(vector<int> v){
  vector<pii> st;
  int len = (int)v.size();
  for(int i = 1 ; i < (1<<len) ; i++){
    int sum = 0, cnt = bit_cnt(i);
    if(cnt>(len+1)/2) continue;
    for(int j = 0 ; j < len ; j++){
      if(i&(1<<j)){
        sum += v[j];
      }
    }
    st.push_back({cnt, sum});
  }
  sort(st.begin(), st.end());
  for(int i = 0 ; i < (int)st.size()-1 ; i ++){
    if(st[i]==st[i+1]||st[i].second >= st[i+1].second) return false;
  }
  return true;
}

vector<int> stov(string s){
  int cnt = 1, tmp = 0;
  vector<int> ret;
  for(auto i : s){
    if(i==','){
      ret.push_back(tmp);
      tmp = 0;
      cnt++;
    }
    else{
      tmp = tmp * 10 + i-'0';
    }
  }
  ret.push_back(tmp);
  return ret;
}

int main(){
  int ans = 0;
  freopen("p105_sets.txt", "r",stdin);
  for(int i = 0 ; i < 100 ; i++){
    string s; cin >> s;
    vector<int> v = stov(s);
    if(ans_check(v)){
      ans += vector_sum(v);
    }
  }
  cout << ans;
}
