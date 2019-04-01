#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n,m,d[10005][10005],s[10005];
ll MOD;

void init(){
    d[0][0]=1;
    for(int i = 1 ; i <= m+2 ; i++){
        d[i][0] = d[i][i] = 1;
        for(int j = 1 ; j < i;j++){
            d[i][j] = (d[i-1][j]+d[i-1][j-1]) % MOD;
        }
    }
}

ll pw(ll x,ll y){
    ll ret = 1;
    while(y){
        if(y&1)ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        y>>=1;
    }
    return ret;
}

ll inv(ll x){ return pw(x,MOD-2);}

ll ans = 0;

void process(ll mod){
    n = 1e12; m = 1e4;
    n %= mod;
    MOD = mod;
    init();
    s[0] = n;
    for(int i = 1 ; i <= m+1 ; i++){
        s[i] = (pw(n+1,i+1)-1+MOD)%MOD;
        for(int j = 2 ; j <= i+1 ; j++){
            s[i] = (s[i]+MOD-(d[i+1][j]*s[i-j+1])%MOD)%MOD;
        }
        s[i]=(s[i]*inv(d[i+1][1]))%MOD;

    }
    ans += (((n+1)%MOD)*s[m]%MOD-s[m+1]+MOD) % MOD ;
}

bool isPrime(ll n){
    for(ll i = 2 ; i*i <= n ; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    ll N = 2e9;
    for(ll i = 1 ; i < 2000 ; i+=2){
        if(isPrime(N+i)){
            process(N+i);
        }
    }
    cout << ans;
}

// 3min
