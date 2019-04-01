#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 50;

ll dp[SZ+1][2];

ll tot(int m){
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1 ; i <= SZ ; i++){
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    if(i>=m) dp[i][1] = dp[i-m][0] + dp[i-m][1];
  }
  return dp[SZ][0] + dp[SZ][1] - 1;
}

int main(){
  cout << tot(2) + tot(3) + tot(4);
}
