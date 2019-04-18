#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e3;

int cycle_len(int n){
    if(n==1) return 0;
    int num = 9, ret = 0;
    while(num){
        num = (num*10+9)%n;
        ret++;
    }
    return ret;
}

int ans, mx;

int main(){
    for(int i = 3 ; i <= SZ ; i++){
        int ii = i;
        while(ii%2==0) ii/=2;
        while(ii%5==0) ii/=5;
        if(mx < cycle_len(ii)){
            ans = ii;
            mx = cycle_len(ii);
        }
    }
    cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

int f(int n){
    while(n%2==0) n/=2;
    while(n%5==0) n/=5;
    vector<int> v(n);
    int st = 1;
    v[st] = 1;
    for(int i = 2; ; i++){
        st = st*10%n;
        if(v[st]){
            return i - v[st];
        }
        v[st] = i;
    }
}

int f2(int n){
    while(n%2==0) n/=2;
    while(n%5==0) n/=5;
    int st = 9;
    for(int i = 0 ; ; i++){
        if(st==0) return i;
        st = (st*10+9)%n;
    }
}


int main(){
    int mxlen = -1, ans = 0;
    for(int i = 1 ; i <= 1000 ; i++){
        int l = f2(i);
        if(mxlen < l){
            mxlen = l;
            ans = i;
        }
    }
    cout << ans;
}

*/
