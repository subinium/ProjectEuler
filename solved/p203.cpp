#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 51;

ll dp[SZ+1][SZ+1];

ll sq_free(ll n){
    for(ll j = 2 ; j*j <= n ; j++){
        if(n%(j*j)==0) return 0;
    }
    return n;
}

int main(){
    set<ll> st;
    dp[1][1] = 1;
    for(int i = 2 ; i <= SZ ; i++){
        for(int j = 1 ; j <= i ; j++){
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
            st.insert(dp[i][j]);
        }
    }
    ll ans = 0;
    for(ll i : st){
        ans += sq_free(i);
    }
    cout << ans;
}
