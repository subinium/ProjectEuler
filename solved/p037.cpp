#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int cnt = 0;
ll ans = 23;
bool isprime(int n){
  if(n==1) return false;
  for(int i = 2 ; i*i <= n ; i++) if(n%i==0) return false;
  return true;
}

bool ck(ll n){
  ll m = n;
  while(m){
    if(!isprime(m)) return false;
    m /= 10;
  }
  ll res = 0;
  ll flag = 1;
  while(n){
    res += (n%10)*flag;
    flag *= 10;
    n /= 10;
    if(!isprime(res)) return false;
  }
  return true;
}


void dfs(ll res){
  if(res&&!isprime(res)) return;
  if(res>10&&ck(res)){
    cnt++;
    ans += res;
    cout << res << endl;
  }
  for(int i =  1 ; i < 10 ; i+=2) dfs(res*10+i);
}

int main(){
  dfs(0);
  cout << cnt << ' ' << ans << endl;
}
