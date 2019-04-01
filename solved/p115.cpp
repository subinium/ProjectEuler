#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1000;
const int m = 50;
const int MX = 1e6;

ll dp[SZ][2];

int main(){
  dp[0][0] = 1;
  for(int i = 1 ; ; i++){
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    if(i>=m) dp[i][1] = dp[i-1][1] + dp[i-m][0];
    if(dp[i][0]>MX){
      cout << i - 1;
      return 0;
    }
  }
}
