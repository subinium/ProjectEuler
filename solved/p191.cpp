#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 30;
ll dp[SZ+1][2][3];

int main(){
    dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
    for(int i = 2 ; i <= SZ ; i++){
        dp[i][0][0] = dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2];
        dp[i][1][0] = dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2]+dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][1][2];
        dp[i][0][1] = dp[i-1][0][0]; dp[i][1][1] = dp[i-1][1][0];
        dp[i][0][2] = dp[i-1][0][1]; dp[i][1][2] = dp[i-1][1][1];

    }

    ll sum = 0;
    for(int j = 0 ; j < 2 ; j++){
        for(int k = 0 ; k < 3 ; k++){
            sum += dp[SZ][j][k] ;
        }
    }
    cout << sum;
}
