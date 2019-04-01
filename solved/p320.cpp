#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e18, SZ = 1e6;

ll f[SZ+10],num[SZ+10],prime[SZ+10];
ll m;
ll result[SZ+10] ={1,1};


ll bs(ll p,ll power) {
    ll lo = 0, hi = p*power;
    while(lo < hi){
        ll mid = (lo+hi)/2;

        ll k = mid;
        ll cnt = 0;
        while(mid){
            cnt += mid/p;
            mid/=p;
        }
        if(cnt < power) lo = k+1;
        else hi = k;
    }
    return lo;
}

void init(){
    ll n = SZ;
    for (int i = 2; i <= n; ++i) {
        if(f[i]) continue;
        prime[++m] = i;
        f[i] = m;
        if (n / i >= i) {
            for (int j = i * i ; j <= n; j += i) {
                if (!f[j]) f[j] = m;
            }
        }
    }
    ll answer = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j > 1; ) {
            ll x = f[j];
            for (; f[j] == x; j /= prime[x], num[x]++);
            answer = max(answer,bs(prime[x], num[x]*1234567890));
        }
        result[i] = answer;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    ll ans = 0;
    for(int i = 10 ; i <= SZ ; i++){
        ans += result[i];
        ans %= MOD;
    }
    cout << ans;
}
