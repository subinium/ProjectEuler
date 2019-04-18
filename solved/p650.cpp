#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const ll N = 20000;
vector<ll> p;
vector<pair<ll, ll> > p_list[N+1];

void era(){
    vector<bool> ck(N+1);
    for(ll i = 2 ; i <= N ; i++){
        if(ck[i]) continue;
        p.push_back(i);
        for(ll j = i ; j <= N ; j+=i){
            ck[j] = true;
            ll jj = j;
            int cnt = 0;
            while(jj%i==0){
                cnt++;
                jj /= i;
            }
            p_list[j].push_back({i,cnt});
        }
    }
}

ll pow(ll a, ll b, ll mod){
    ll ret = 1;
    while(b){
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return ret;
}

ll pow_sum(ll n, ll times){
    return (pow(n,times+1, MOD)-1) * pow(n-1, MOD-2, MOD) % MOD;
}

ll D(ll n){
    vector<ll> pcnt(n+1);
    for(int i = 2 ; i <= n ; i++){
        for(auto x : p_list[i]) pcnt[x.first]+= (n-1)*x.second;
    }
    for(int i = 2 ; i < n ; i++) for(auto x : p_list[i]) pcnt[x.first]-= 2*(n-i)*x.second;
    ll ret = 1;
    for(int x = 2 ; x <= n ; x++){
        ret = ret * pow_sum(x, pcnt[x]) % MOD;

    }
    return ret;
}

void S(ll n){
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++) ans = (ans + D(i)) % MOD;
    cout << ans;
}

int main(){
    era();
    S(N);
}

// 23s
// using pair 22s
