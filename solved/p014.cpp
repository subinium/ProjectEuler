#include <stdio.h>
#define ll long long

int arr[10000000]={0,1};

int doit(ll n){
    if(n<10000000&&arr[n]) return arr[n];
    if(n%2==0){
        return 1+doit(n/2);
    }
    else{
        return 1+doit(3*n+1);
    }

}

int main(){
    int maxlen = 0;
    int flag = 0;
    for(ll i = 1 ; i <= 1000000; i++){
        arr[i] = doit(i);
        if(maxlen<arr[i]){
            maxlen = arr[i];
            flag = i;
        }
    }
    printf("%d",flag);
}
