#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;

const int SZ = 1e4;

ll gcd(ll a, ll b){
    return a%b?gcd(b,a%b):b;
}

int find_cycle(ll n){
    int cnt = 0;
    set<pll> st;
    pll flag = pll(sqrt(n),1);
    while(!st.count(flag)){
        st.insert(flag);
        ll mo = n-flag.fi*flag.fi;
        if(mo==0) return 0;
        ll so = flag.se ;
        ll g = gcd(mo,so);
        mo /= g; so /= g;
        so *= flag.fi;
        ll tmp = (sqrt(n) + so) / mo;
        so -= mo*tmp;
        flag = pll(-so,mo);
        cnt++;
    }
    return cnt;
}

int main(){
    int ans = 0;
    for(int i = 2 ; i <= SZ ; i++){
        ans += find_cycle(i) & 1;
    }
    cout << ans;
}
