#include <stdio.h>

int arr[10001];

int main(){
    for(int i = 1 ; i <= 10000 ; i++){
        for(int j = 2*i ; j <= 10000 ; j+= i){
            arr[j] += i;
        }
    }
    int tot = 0;
    for(int i = 1 ; i <= 10000 ; i++){
        if(arr[i]<=10000&&arr[arr[i]]==i&&i!=arr[i]){
            tot += i;
        }
    }
    printf("%d",tot);
}
