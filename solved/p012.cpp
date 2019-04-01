#include <stdio.h>
#define ll long long

ll cnt_div(ll num){
    ll tot = 1;
    ll p = 2;
    ll pcnt = 0;
    while(p<=num){
        if(num%p==0){
            pcnt++;
            num/=p;
        }
        else{
            if(p>2) p += 2;
            else p++;
            tot *= pcnt+1;
            pcnt = 0;
        }
    }
    tot *= pcnt+1;
    return tot;
}

int main(){
    ll num = 50005000;
    for(ll i = 10001;;i++){
        num += i;
        if(cnt_div(num)>=500){
            printf("num : %lld\n",num);
            break;
        }
    }
}
