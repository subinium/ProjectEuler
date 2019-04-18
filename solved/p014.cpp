#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;

int dp[MAXN+5];
map<ll, int> dp2;

int f(ll ith){
    int &ret = ith > MAXN ? dp2[ith] : dp[ith];
    if(ret) return ret;
    if(ith&1) return ret = f(ith*3+1)+1;
    return ret = f(ith/2)+1;
}

int main(){
    dp[1] = 1;
    int mi = 0;
    for(ll i = 2 ; i <= MAXN ; i++){
        dp[i] = f(i);
        if(dp[i] > dp[mi]){
            mi = i;
        }
    }
    cout << mi << endl;
    cout << dp[mi] << endl;
}
