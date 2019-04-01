#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 15;
const int MX = 4e6;

vector<ll> p;
int arr[100];

void era(){
  int cnt = SZ;
  for(int i = 2 ; cnt ; i++ ){
    if(arr[i]) continue;
    p.push_back(i);
    cnt--;
    for(int j = i*i; j < 100 ; j+=i){
      arr[j] = 1;
    }
  }
}

ll ans = 1;

void dfs(int idx, ll val, int cnt, int last){
  if( (cnt+1)/2 > MX){
    ans = min(ans, val);
    return ;
  }
  ll pri = p[idx];
  for(int i = 0 ; val < ans / pri && i <= last ; i++){
    dfs(idx+1, val * pri, cnt*(2*(i+1)+1), i);
    pri *= p[idx];
  }
}

int main(){
  era();
  ll cnt = 1;
  for(int i = 0 ; i < SZ ; i++ ) ans *= p[i];
  dfs(0, 1, 1, 40);
  cout << ans;
}
