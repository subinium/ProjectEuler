#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e8;

int phi[SZ+1], dp[SZ+1], hf[SZ+1];

void era(){
    for(int i = 1 ; i <= SZ ; i++) phi[i] = i;
    for(int i = 2 ; i <= SZ ; i++){
        if(phi[i]!=i) continue;
        for(int j = i ; j <= SZ ; j+=i){
            phi[j] = phi[j]/i*(i-1);
            hf[j] = i;
        }
    }
}

ll power(ll a, ll b, ll mod){
    ll ret = 1;
    while(b){
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

ll gcd(ll a, ll b){ return a%b?gcd(b,a%b):b;}
ll lcm(ll a, ll b){ return a*b/gcd(a,b);}

int main(){
    era();
    ll ans = 0;
    for(int i = 3 ; i <= SZ ; i++){
        int n = i;
        while(n%2==0) n /= 2;
        while(n%5==0) n /= 5;
        if(n==1) continue;
        if(dp[n]){
            ans += (ll)dp[n];
            continue;
        }
        int d = phi[n];
        while(true){
            bool ck = true;
            for(int p = d ; p > 1 ; p = p/hf[p]){
                int pri = hf[p];
                if(power(10,d/pri,n)==1){
                    d /= pri;
                    ck = false;
                    break;
                }
            }
            if(ck){
                dp[n] = d;
                ans += (ll)d;
                break;
            }
        }
    }
    cout << ans;
}
