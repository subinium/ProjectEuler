#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1<<20, LEN = 18;
// 4^10 = 2^20 
ll dp[LEN+1][SZ+1];
int four[11] = {1};

int main(){
  for(int i = 1 ; i <= 10 ; i++) four[i] = four[i-1]*4;
  dp[0][0] = 1;
  for(int i = 1 ; i <= LEN ; i++){
    for(int j = 0 ; j <= SZ ; j++){
      if(i==1 && j == 1) continue;
      for(int k = 0; k < 10 ; k++){
        if((j%four[k+1])/four[k]) dp[i][j] += dp[i-1][j-four[k]];
      }
    }
  }
  ll ans = 0;
  for(int i = 0 ; i <= SZ ; i++) ans += dp[LEN][i];
  cout << ans;
}
