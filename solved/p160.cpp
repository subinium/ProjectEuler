#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e12, MOD = 1e5;

ll even_fac(ll n);
ll odd_fac(ll n);
ll fac(ll n);
ll dp[MOD];

ll power(ll a, ll b, ll mod){
    ll ret = 1;
    a %= mod;
    while(b){
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

ll pcnt(ll n, ll p){
    return n ? n/p + pcnt(n/p, p) : 0;
}

ll even_fac(ll n){
    return n?fac(n/2):1;
}

ll odd_fac(ll n){
    return n?odd_fac(n/5)*dp[n%MOD]%MOD:1;
}

ll fac(ll n){
    return even_fac(n) * odd_fac(n) % MOD;
}

ll fac_co(ll n){
    n %= MOD;
    ll ret = 1;
    for(ll i = 1 ; i <= n ; i++){
        if(i%2&&i%5) ret = ret * i % MOD;
    }
    return ret;
}

ll fac_five(ll n){
    ll two_cnt = pcnt(n,2) - pcnt(n,5);
    return fac(n) * power(2,two_cnt, MOD) % MOD;
}

int main(){
    dp[0] = 1;
    for(ll i = 1 ; i < MOD ; i++){
        if(i%2&&i%5) dp[i] = dp[i-1]*i%MOD;
        else dp[i] = dp[i-1];
    }
    cout << fac_five(SZ);
}
