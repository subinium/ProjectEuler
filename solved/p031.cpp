#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SZ = 200;

int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[SZ+1][8];

int main(){
    dp[0][0] = 1;
    for(int i = 1 ; i <= SZ ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(i-coin[j] < 0) break;
            for(int k = 0 ; k <= j ; k++){
                dp[i][j] += dp[i-coin[j]][k];
            }
        }
    }
    int sum = 0;
    for(int i = 0 ; i < 8 ; i++) sum += dp[SZ][i];
    cout << sum;


}
