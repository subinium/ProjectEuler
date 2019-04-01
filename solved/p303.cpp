#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 100;

ll process(ll i){
    queue<ll> q;
    vector<bool> ck(i,false);
    q.push(1ll); q.push(2ll);
    while(!q.empty()){
        ll f = q.front(); q.pop();
        if(ck[f%i]) continue;
        ck[f%i] = true;
        if(f%i==0) return f/i;
        q.push(f*10);
        q.push(f*10 + 1);
        q.push(f*10 + 2);
    }
    return 0;
}

int main(){
    ll ans = 1111333355557778;
    for(ll i = 1 ; i <= 9998 ; i++){
        ans += process(i);
    }
    ans += process(10000);
    cout << ans;
}
