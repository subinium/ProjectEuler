#include <stdio.h>

int main(){
    for(int i = 1 ; i < 1000 ; i++){
        for(int j = i ; j < 1000 ; j++ ){
            int tmp = 1000 - i - j;
            if(i*i + j *j == tmp*tmp){
                printf("%d",i*j*tmp);
            }
        }
    }
}
