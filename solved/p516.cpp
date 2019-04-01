#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll SZ = 1e12, sz = 1e6, MOD = 1ll<<32;

vector<ll> pr, P, ttf;
bool arr[sz];

void era(){
    for(ll i = 2 ; i <= sz ; i++){
        if(arr[i]) continue;
        pr.push_back(i);
        for(ll j = i*i ; j <= sz ; j+= i){
            arr[j] = true;
        }
    }
}

bool isPrime(ll n){
    for(auto i : pr){
        if(i*i>n) break;
        if(n%i==0) return false;
    }
    return true;
}

void dfs(ll n, ll ed){
    if(n>SZ) return ;
    if(isPrime(n+1)&&n+1>5) P.push_back(n+1);
    ttf.push_back(n);
    if(ed<=2) dfs(n*2,2);
    if(ed<=3) dfs(n*3,3);
    if(ed<=5) dfs(n*5,5);
}

ll ans;

void dfs2(ll val, ll idx){
    if(idx == P.size()) return;
    if(val>SZ/P[idx]) return ;
    ll tmp = val * P[idx];
    if(tmp<SZ){
        ans += tmp;
        ans %= MOD;
        dfs2(tmp, idx+1);
    }
    dfs2(val,idx+1);
}

int main() {
    era();
    dfs(1,2);
    sort(P.begin(), P.end());
    sort(ttf.begin(), ttf.end());
    for(auto i : ttf){
        ans += i;
        ans %= MOD;
        dfs2(i,0);
    }
    cout << ans - 1;
}
