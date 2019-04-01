#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e8;

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

ll tetration(ll a, ll b, ll mod){
    ll last = 0;
    ll res = 1;
    while(b--){
        res = power(a,res,mod);
        if(last==res) break;
        last = res;
    }
    return res;
}

int main(){
    ll a = 1777, b = 1855;
    cout << tetration(a, b, MOD);
}
