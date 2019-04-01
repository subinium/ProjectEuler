#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 20;

ll dp[100][SZ+1];

ll ds(int a){
    return a%10 + a/10;
}

int main(){
    for(int i = 1; i < 10 ; i++) dp[i][1] = 1;
    for(int i = 1 ; i < SZ ; i++){
        for(int j = 0 ; j < 100 ; j++){
            for(int k = 0 ; k <= 9-ds(j) ; k++){
                dp[(j%10)*10+k][i+1] += dp[j][i];
            }
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < 100 ; i++){
        ans += dp[i][SZ];
    }
    cout << ans;
}
