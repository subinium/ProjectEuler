#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> cand = {20,31,38,39,40,42,45};
vector<int> ans;
int tot_sum ;

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

void dfs(int idx, vector<int> v){
  if(idx==cand.size()){
    if(vector_sum(v) < tot_sum && ans_check(v)){
      ans = v;
      tot_sum = vector_sum(v);
    }
    return ;
  }
  for(int i = -3 ; i < 3 ; i++){
    v.push_back(cand[idx]+i);
    dfs(idx+1,v);
    v.pop_back();
  }
}

int main(){
  ans = cand;
  tot_sum = vector_sum(ans);
  vector<int> tmp; dfs(0,tmp);
  for(auto i : ans) cout << i;
}
