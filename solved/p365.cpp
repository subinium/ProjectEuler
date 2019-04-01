#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll N = 1e18, M = 1e9;
const int SZ = 5005, pcnt = 505;

bool arr[SZ];
int cnt;
vector<ll> fac[pcnt], inv_fac[pcnt];
vector<ll> p;
ll ncm[pcnt];

ll power(ll a, ll b, ll mod){
    ll ret = 1;
    a %= mod;
    while(b){
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

ll combi(ll n, ll m, ll mod_idx){
    ll pr = p[mod_idx];
    if(n < m) return 0;
    return fac[mod_idx][n]*inv_fac[mod_idx][m]%pr*inv_fac[mod_idx][n-m]%pr;
}

ll lucas(ll n, ll m, ll mod_idx){
    ll ret = 1, pr = p[mod_idx];
    while(n||m){
        ret *= combi(n%pr,m%pr,mod_idx);
        ret %= pr;
        n /= pr;
        m /= pr;
    }
    return ret;
}

ll crt(vector<ll> pr, vector<ll> rem){
    ll ret =
        power(pr[0]*pr[1],pr[2]-2,pr[2])*pr[0]*pr[1]*rem[2]+
        power(pr[0]*pr[2],pr[1]-2,pr[1])*pr[0]*pr[2]*rem[1]+
        power(pr[1]*pr[2],pr[0]-2,pr[0])*pr[1]*pr[2]*rem[0];
    return ret % (pr[0]*pr[1]*pr[2]);
}

void era(){
    int lo = 1000, hi = 5000;
    for(int i = 2 ; i <= SZ ; i++){
        if(arr[i]) continue;
        if(i>lo&&i<hi){
            ll tmp = 1;
            for(int j = 1 ; j <= i ; j++){
                fac[cnt].push_back(tmp);
                inv_fac[cnt].push_back(power(tmp,i-2,i));
                tmp = tmp*j % i;
            }
            p.push_back(i);
            ncm[cnt] = lucas(N,M,cnt);
            cnt++;
        }
        for(int j = i*i ; j <= hi ; j += i){
            arr[j] = true;
        }
    }
}

ll ans = 0;

int main(){
    era();
    for(int i = 0 ; i < p.size() ; i++){
        for(int j = i+1 ; j < p.size() ; j++){
            for(int k = j+1 ; k < p.size() ; k++){
                vector<ll> pp(3), rr(3);
                pp[0] = p[i]; pp[1] = p[j]; pp[2] = p[k];
                rr[0] = ncm[i]; rr[1] = ncm[j]; rr[2] = ncm[k];
                ans += crt(pp,rr);
            }
        }
    }
    cout << ans;
}

// 33 sec
