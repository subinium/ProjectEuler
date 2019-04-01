#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 200;

int ans[SZ+1];

void dfs(vector<int> v, int tot, int cnt, int n){
  if(tot==n){
    ans[n] = cnt;
    return ;
  }
  if(cnt>=ans[n]) return ;
  v.push_back(tot);
  for(int i = 0 ; i < v.size() ; i++){
    dfs(v, tot+v[i], cnt+1, n);
  }

}

void process(int n){
  vector<int> v;
  dfs(v,1,0,n);
}

int binary(int n){
  int cnt = 0;
  int m = n;
  while(n){
    if(n&1) cnt++;
    cnt++;
    n /= 2;
  }
  return cnt;
}

int main(){
  for(int i = 2 ; i <= 200 ; i++) ans[i] = binary(i), process(i);
  int ANS = 0;
  for(int i = 2 ; i <= SZ ; i++) ANS += ans[i];
  cout << ANS;

}
