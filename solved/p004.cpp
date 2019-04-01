#include <stdio.h>

int check_palin(int n){
    if(n<100000){
        if(n/10000==n%10&&(n/1000)%10==(n/10)%10)
            return n;
    }
    else{
        if(n/100000==n%10&&(n/10000)%10==(n/10)%10&&(n/1000)%10==(n/100)%10)
            return n;
    }
    return 0;
}

int main(){
    int maxnum = 10000;
    for(int i = 100 ; i < 1000 ; i++){
        for(int j = 100 ; j < 1000 ; j++){
            int tmp = check_palin(i*j);
            maxnum = maxnum > tmp ? maxnum : tmp;
        }
    }
    printf("%d",maxnum);
}
