#include <stdio.h>

int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int my(int n){
    if(n%4==0&&(n%100!=0||n%400==0)){
        return 1;
    }
    return 0;
}

int main(){
    int st = 2;
    int cnt = 0;
    for(int i = 1901; i <= 2000 ; i++){
        for(int j = 1 ; j <= 12 ; j++){
            if(st==6) cnt++;
            st += mon[j];
            if(j == 2) st += my(i);
            st %= 7;
        }
    }
    printf("%d",cnt);
}
