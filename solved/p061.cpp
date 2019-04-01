#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e4;
const int TP = 6;
int arr[SZ][6];

void dfs(int ck, int tot, int lst, vector<int> v){
  if(ck==(1<<TP)-1 && v[0]/100 == v[TP-1]%100){
    cout << tot << endl;
    for(int i = 0 ; i < TP ; i++){
      cout << v[i] << ' ';
    }
    exit(0) ;
  }
  for(int i = 10 ; i < 100 ; i++ ){
    for(int j = 0 ; j < TP ; j++){
      if(ck&(1<<j)) continue;
      if(!arr[lst*100+i][j]) continue;
      vector<int> vv = v;
      vv.push_back(lst*100+i);
      dfs(ck|(1<<j),tot+lst*100+i,i,vv);
    }
  }
}

int main(){
  for(int i = 0 ; i*(i+1)/2 < SZ ; i++) arr[i*(i+1)/2][0] = 1;
  for(int i = 0 ; i*i < SZ ; i++) arr[i*i][1] = 1;
  for(int i = 0 ; i*(3*i-1)/2 < SZ ; i++) arr[i*(3*i-1)/2][2] = 1;
  for(int i = 0 ; i*(2*i-1) < SZ ; i++) arr[i*(2*i-1)][3] = 1;
  for(int i = 0 ; i*(5*i-3)/2 < SZ ; i++) arr[i*(5*i-3)/2][4] = 1;
  for(int i = 0 ; i*(3*i-2) < SZ ; i++) arr[i*(3*i-2)][5] = 1;
  vector<int> v;
  for(int i = 10 ; i < 100 ; i++) dfs(0,0,i,v);
}
