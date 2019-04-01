#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char arr[11]="0123456789";

int main(){
    for(int i = 1 ; i < 1000000 ; i++){
        next_permutation(arr,arr+10);
    }
    printf("%s",arr);
}
