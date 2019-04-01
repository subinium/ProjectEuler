#include <stdio.h>

int arr[1005];

int main(){
    int tot = 0;
    for(int i = 1 ; i <= 1000 ; i++){
        if(i%3==0||i%5==0) tot += i;
    }
    printf("%d",tot);
}
