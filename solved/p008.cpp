#include <stdio.h>
#define ll long long

char arr[2000];

int main(){
    for(int i = 0; i < 1000 ; i++){
        scanf(" %c",arr+i);
        arr[i]-='0';
    }
    ll max = 0;
    for(int i = 0 ; i < 988 ; i++){
        ll tmp = 1;
        for(int j = 0 ; j < 13 ; j++){
            tmp *= arr[i+j];
        }
        max = max > tmp ? max : tmp;
    }
    printf("%lld",max);
}
