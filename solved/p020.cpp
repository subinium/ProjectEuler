#include <stdio.h>

int arr[500] = {1,};


int main(){
    for(int i = 1 ; i <= 100 ; i++){
        for(int j = 0 ; j < 500 ; j++){
            arr[j] *= i;
        }
        for(int j = 0 ; j < 499 ; j++){
            if(arr[j]>=10) arr[j+1] += arr[j]/10;
            arr[j] %= 10;
        }
    }
    int tot = 0;
    for(int i = 0 ; i < 500 ; i++){
        tot += arr[i];
    }
    printf("%d",tot);
}
