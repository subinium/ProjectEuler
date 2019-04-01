#include <stdio.h>

int arr[100][100];

int main(){
    for(int i = 1 ; i <= 15 ; i++){
        for(int j = 1 ; j <= i; j++){
            scanf("%d",&arr[i][j]);
            arr[i][j] += arr[i-1][j-1]>arr[i-1][j]?arr[i-1][j-1]:arr[i-1][j];
        }
    }
    int max = 0;
    for(int i = 1 ; i <= 15 ; i++){
        max = arr[15][i] > max ? arr[15][i]:max;
    }
    printf("%d",max);
}
