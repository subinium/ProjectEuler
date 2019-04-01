#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 51;

ll dp[SZ+1][4];

ll tot(){
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1 ; i <= SZ ; i++){
    for(int j = 0 ; j < 4 ; j++) dp[i][0] += dp[i-1][j];
    for(int m = 2 ; m <= 4 ; m++){
      if(i>=m) for(int j = 0 ; j < 4 ; j++) dp[i][m-1] += dp[i-m][j];
    }
  }
  return dp[SZ][0];
}

int main(){
  cout << tot();
}
