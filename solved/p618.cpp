#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 24, MOD = 1e9, N = 1e5;

ll fac[SZ+1] = {0,1};
bool arr[N];
vector<ll> p;

void era(){
    for(int i = 2 ; i < N ; i++){
        if(arr[i]) continue;
        p.push_back(i);
        for(int j = 2*i ; j < N ; j+=i){
            arr[j] = true;
        }
    }
}

int main(){
    era();
    for(int i = 2 ; i <= SZ ; i++){
        fac[i] = fac[i-1] + fac[i-2];
    }
    vector<ll> v(fac[SZ]+1,0);
    v[0] = 1;
    for(auto i : p ){
        for(ll j = i ; j < v.size() ; j++){
            v[j] += v[j-i]*i%MOD;
            v[j] %= MOD;
        }
    }
    ll ans = 0;
    for(int i = 2 ; i <= SZ ; i++){
        ans += v[fac[i]];
        ans %= MOD;
    }
    cout << ans;
}
