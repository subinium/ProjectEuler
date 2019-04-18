#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000000;

void process1(){
    string s = "0123456789";
    for(int i = 0 ; i < N-1 ; i++) next_permutation(s.begin(), s.end());
    cout << s << endl;
}

bool ck[10];
int fac[10];

void f(int nth, int len){
    if(len==0){
        return;
    }
    int x = nth/fac[len-1] + 1;
    int cnt = 0;
    for(int i = 0 ; i < 10 ; i++){
        cnt += !ck[i];
        if(cnt==x){
            cout << i;
            ck[i] = true;
            f(nth % fac[len-1], len-1);
            break;
        }
    }
}


void process2(){
    fac[0] = 1;
    for(int i = 1 ; i < 10 ; i++) fac[i] = fac[i-1] * i;
    f(N-1, 10);
}

int main(){
    process1();
    process2();
}
