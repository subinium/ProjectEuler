#include <stdio.h>

int arr[500];

int main(){
    arr[0] = 1;
    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j < 500 ; j++){
            arr[j] *= 2;
        }
        for(int j = 0 ; j < 500 ; j++){
            if(arr[j]>9){
                arr[j+1] += arr[j]/10;
                arr[j] %= 10;
            }
        }
    }
    int sum = 0;
    for(int i = 0 ; i < 500 ; i++){
        sum += arr[i];
    }
    printf("%d\n",sum);
}
