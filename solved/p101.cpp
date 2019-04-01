#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SZ = 10;

ll kth[SZ*2];

ll gcd(ll x, ll y){
    return x%y?gcd(y,x%y):y;
}

ll f(ll x){
    ll ret = 0, st = 1;
    for(int i = 0 ; i <= SZ ; i++){
        ret += st; st *= -x;
    }
    return ret;
}

ll BOP(ll k, ll x){
    ll ret = 0;
    for(int i = 0 ; i <= k ; i++){
        ll mo = 1, so = 1;
        for(int j = 0 ; j <= k ; j++){
            if(i==j) continue;
            ll g = gcd(abs(x-j+1),abs(i-j));
            mo *= (x-j+1)/g;
            so *= (i-j)/g;
        }
        mo *= f(i+1);
        ret += mo / so;
    }
    return ret;
}

ll FIT(int k){
    for(ll i = k ; ; i++){
        if(BOP(k,i)!=f(i)){
            return BOP(k,i);
        }
    }
    return 0;
}

int main(){
    ll ans = 0;
    for(int i = 0 ; i < SZ ; i++) ans += FIT(i);
    cout << ans;
}
