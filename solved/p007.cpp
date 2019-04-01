#include <stdio.h>

int arr[1000000];

int main(){
    int cnt = 0;
    for(int i = 2 ; i < 1000000; i++){
        if(arr[i]==0){
            cnt++;
            for(int j = 2 * i ; j < 1000000 ; j+=i){
                arr[j] = 1;
            }
            if(cnt == 10001){
                printf("%d",i);
                break;
            }
        }
    }
}
