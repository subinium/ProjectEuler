#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll SZ = 12345;

ll ans;

ll tri(ll n){
    return n*(n+1)/2;
}

ll hexa(ll n){
    ll ret = 0;
    for(ll i = 1 ; i*3 <= n ; i++) ret += i*tri(n-3*i+1);
    return ret;
}

int main(){
    for(ll i = 3 ; i <= SZ ; i++) ans += hexa(i);
    cout << ans;

}
