#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    return a%b?gcd(b,a%b):b;
}

int main(){
    int x = 1, y = 1;
    for(int i = 10 ; i <= 99 ; i++){
        for(int j = i+1 ; j <= 99 ; j++){
            if(i%10==j/10){
                int ii = i/10;
                int jj = j%10;
                if(i*jj == ii*j){
                    x *= i;
                    y *= j;
                }
            }
            if(i/10==j%10){
                int ii = i%10;
                int jj = j/10;
                if(i*jj == ii*j){
                    x *= i;
                    y *= j;
                }
            }
        }
    }
    int g = gcd(x,y);
    cout << y/g << endl;
}
