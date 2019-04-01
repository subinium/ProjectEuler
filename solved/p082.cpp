#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 80;

int arr[SZ+1][SZ+1];
int dp[SZ+1][SZ+1][2];

int main(){
  freopen("p082_matrix.txt","r",stdin);
  for(int i = 1 ; i <= SZ ; i++){
    for(int j = 1 ; j <= SZ ; j++){
      scanf("%d,",&arr[j][i]);
    }
  }
  for(int i = 1 ; i <= SZ ; i++){
    dp[i][1][0] = dp[i-1][1][0] + arr[i][1];
    for(int j = 2 ; j <= SZ ; j++){
      dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]);
      dp[i][j][0] = min(dp[i][j][0],dp[i][j-1][0]);
      dp[i][j][0] += arr[i][j];
    }
    dp[i][SZ][1] = dp[i-1][SZ][1] + arr[i][SZ];
    for(int j = SZ-1 ; j >= 1 ; j--){
      dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][1]);
      dp[i][j][1] = min(dp[i][j][1],dp[i][j+1][1]);
      dp[i][j][1] += arr[i][j];
    }
  }
  int ans = 1e9;
  for(int i = 1 ; i <=SZ ; i++){
    ans = min(ans,dp[SZ][i][0]);
    ans = min(ans,dp[SZ][i][1]);
  }
  cout << ans;
}
