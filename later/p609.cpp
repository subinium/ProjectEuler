#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9+7, SZ = 10;

int p[SZ+1];
int dp[SZ+1];
int cnt[SZ+1], cnt2[SZ+1];


void era(){
  p[1] = 1; 
  for(ll i = 2 ; i <= SZ ; i++){
    cnt[i] = cnt[i-1];
    if(p[i]) continue;
    cnt[i]++;
    for(ll j = i*i ; j <= SZ ; j+=i){
      p[j] = 1;
    }
  }
}

int main(){
  era();
}
