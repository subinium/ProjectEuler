#include <stdio.h>
#define MAX(x,y) (x)>(y)?(x):(y)

int arr[28][28];
int dx[4] = {0,1,1,1}, dy[4] = {1,-1,0,1};

int main(){
    int maxnum = 0;
    for(int i = 4 ; i <= 23 ; i++){
        for(int j = 4 ; j <= 23 ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 4 ; i <= 23 ; i++){
        for(int j = 4 ; j <= 23 ; j++){
            for(int k = 0 ; k < 4 ; k++){
                int tmp = arr[i][j];
                for(int w = 1 ; w <= 3 ; w++){
                    tmp *= arr[i+w*dx[k]][j+w*dy[k]];
                }
                maxnum = MAX(maxnum,tmp);
            }
        }
    }
    printf("%d",maxnum);
}
