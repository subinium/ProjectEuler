#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int> > v;
int arr[10];
int ck[8] = {1,4,6,16,25,36,46,81};

void dfs(int i, vector<int> val){
  if(val.size()==6){
    v.push_back(val);
    return ;
  }
  if(i==10) return ;
  dfs(i+1,val);
  val.push_back(arr[i]);
  dfs(i+1,val);
}

int f(vector<int> a, vector<int> b){
  set<int> s;
  for(int i = 0 ; i < a.size() ; i++){
    for(int j = 0 ; j < b.size() ; j++){
      s.insert(a[i]*10+b[j]);
      s.insert(b[j]*10+a[i]);
    }
  }
  for(int i = 0 ; i < 8 ; i++){
    if(!s.count(ck[i])) return 0;
  }
  return 1;
}

int main(){
  for(int i = 0 ; i < 9 ; i++) arr[i] = i;
  arr[9] = 6;
  vector<int> tmp;
  dfs(0,tmp);
  int ans = 0;
  for(int i = 0 ; i < v.size() ; i++){
    for(int j = i ; j < v.size() ; j++){
      ans += f(v[i],v[j]);
    }
  }
  cout << ans;
}
