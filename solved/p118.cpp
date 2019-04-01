#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1e8;

bool a[SZ];
int digit[10];
int ans[10], fac[10];

void era(){
  a[0]=a[1] = true;
  for(ll i = 2 ; i < SZ ; i++){
    if(a[i]) continue;
    for(ll j = i*i ; j < SZ ; j += i){
      a[j] = true;
    }
  }

}

void dfs(int val, int idx, int cnt){
  if(idx == 10){
    if(!val) ans[cnt]++;
    return ;
  }
  val = val *10 + digit[idx];
  dfs(val,idx+1, cnt);
  if(val < SZ && !a[val]) dfs(0,idx+1,cnt+1);
}

int main(){
  era();
  fac[0] = 1;
  for(int i = 1 ; i <= 9 ; i++) digit[i] = i, fac[i] = fac[i-1]*i;
  do{
    dfs(0,1,0);
  }while(next_permutation(digit+1,digit+10));
  int ANS = 0;
  for(int i = 1 ; i <= 9 ; i++){
    ANS += ans[i] / fac[i];
  }
  cout << ANS;
}
