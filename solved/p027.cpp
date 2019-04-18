#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int aa, bb;

bool ck[3000000];

void era(){
    ck[0] = ck[1] = true;
    for(int i = 2 ; i <= 3000000 ; i++){
        if(ck[i]) continue;
        for(int j = 2*i; j <= 3000000 ; j+=i){
            ck[j] = true;
        }
    }
}

int form(int n, int a, int b){
    return n*n + n*a + b;
}

int f(int a, int b){
    for(int n = 0 ; ; n++){
        int res = form(n, a, b);
        if(res < 0 || ck[res]) return n;
    }
    return -1;
}

int main(){
    era();
    int mxlen = 0;

    for(int a = -999 ; a <= 999 ; a++){
        for(int b = -999 ; b <= 999 ; b++){
            int len = f(a,b);
            if(mxlen < len ){
                mxlen = len;
                aa = a, bb = b;
            }
        }
    }
    cout << aa << ' ' << bb << endl;
    cout << aa*bb << endl;
    cout << mxlen << endl;
}
