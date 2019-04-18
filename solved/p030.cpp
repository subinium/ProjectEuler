#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int five[10];

int f(int n){
    int ret = 0;
    while(n){
        ret += five[n%10];
        n/=10;
    }
    return ret;
}

int main(){
    for(int i = 1 ; i < 10 ; i++){
        five[i] = 1;
        for(int j = 1 ; j <= 5 ; j++) five[i] *= i;
    }
    int sum = 0;
    for(int i = 2; i <= 500000 ; i++){
        if(i==f(i)) sum += i;
    }
    cout << sum;
}
