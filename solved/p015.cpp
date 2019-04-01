#include <stdio.h>
#define ll long long

int main(){
    ll tot = 1;
    for(ll i = 40 ; i >= 21 ; i--){
        tot = (tot*i)/(41-i);
    }
    printf("%lld",tot);
}
