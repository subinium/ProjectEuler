#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 50;

ll dp[SZ+1][2];

int main(){
  dp[0][0] = 1;
  for(int i = 1 ; i <= SZ ; i++){
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    if(i>=3) dp[i][1] = dp[i-1][1] + dp[i-3][0];
  }
  cout << dp[SZ][0] + dp[SZ][1];
}
