#include <stdio.h>
#define ll long long

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}


int main(){
    ll ans = 1;
    for(ll i = 2; i <= 20 ; i++) ans = lcm(ans,i);
    printf("%lld",ans);
}
