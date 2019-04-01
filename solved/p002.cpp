#include <stdio.h>

int main(){
    long long st = 1, snd = 2;
    long long tot = 0;
    while(snd<4000000){
        if(snd%2==0) tot += snd;
        long long tmp = snd;
        snd = st + snd;
        st = tmp;
    }
    printf("%lld",tot);
}
