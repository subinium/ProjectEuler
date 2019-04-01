#include <stdio.h>
#define ll long long

int main(){
    ll num = 600851475143;
    ll p = 2;
    ll maxp = 2;
    while(num>=p){
        if(num%p==0){
            maxp = p;
            num /= p;
        }
        else{
            p++;
        }
    }
    printf("%lld",maxp);
}
