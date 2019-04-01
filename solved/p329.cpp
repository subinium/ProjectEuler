#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int sz = 500, len = 15;

ll mo = 500 * 470184984576 , so;

int p[sz+1];
string s = " PPPPNNPPPNPPNPN";

int gcd(int a, int b){
  return a%b?gcd(b,a%b):b;
}

void era(){
  p[1] = 1;
  for(int i = 2 ; i <= sz ; i++){
    if(p[i]) continue;
    for(int j = i*i ; j <= sz ; j+= i) p[j] = 1;
  }
}

int same(char a, int i){
  if( (a=='N' && i == 1) || (a=='P' && i == 0)) return 2;
  else return 1;
}

void dfs(int idx, int cnt, ll val){
  if(cnt==len+1){
    so += val;
    return;
  }
  val *= same(s[cnt],p[idx]);
  if(idx!=1) dfs(idx-1,cnt+1, val);
  else dfs(idx+1, cnt+1, val );
  if(idx!=sz) dfs(idx+1,cnt+1, val );
  else dfs(idx-1, cnt+1, val );
}

int main(){
  era();
  for(int i = 1 ; i <= sz ; i++) dfs(i, 1, 1);
  int g = gcd(mo,so);
  cout << so/g << '/' << mo/g;
}
