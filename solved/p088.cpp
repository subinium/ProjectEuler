#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 12000;
const ll MX = 1e9;

vector<ll> v(SZ+1, MX);
set<ll> st;
ll ans;

void dfs(ll n, ll pro, ll sum, ll cnt){
    ll tmp = pro-sum+cnt;
    if(tmp < SZ+1){
        if(pro < v[tmp]) v[tmp] = pro;
        for(ll i = n ; i <= (SZ/pro)*2 ; i++){
            dfs(n, pro*i, sum+i, cnt+1);
        }
    }
}

int main(){
    dfs(2,1,1,1);
    for(int i = 2 ; i <= SZ ; i++) st.insert(v[i]);
    for(auto i : st) ans += i;
    cout << ans;
}
