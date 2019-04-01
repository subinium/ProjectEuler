#include <stdio.h>
typedef long long ll;
const int MAX = 2000000

int arr[MAX];

int main(){
    ll tot = 0;
    for(ll i = 2; i < MAX; i++){
        if(arr[i]) continue;
        tot += i;
        for(ll j = i*i; j < MAX; j+=i){
            arr[j] = 1;
        }
    }
    printf("%lld",tot);
}
