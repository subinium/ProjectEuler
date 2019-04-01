#include <stdio.h>

int arr[55];

int main(){
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 1 ; j <= 50 ; j++){
            int tmp;
            scanf("%1d",&tmp);
            arr[j] += tmp;
        }
    }
    for(int i = 50; i >= 1 ; i--){
        if(arr[i]>=10){
            arr[i-1] += arr[i]/10;
            arr[i] %= 10;
        }
    }
    for(int i = 0 ; i <= 50 ; i++){
        printf("%d ",arr[i]);
    }
}
