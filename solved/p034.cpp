#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll fac[10] = {1, };

ll check(ll n){
    ll ret = 0;
    while(n){
        ret += fac[n%10];
        n /= 10;
    }
    return ret;
}

int main(){
    ll sum = 0;
    for(int i = 1 ; i < 10 ; i++) fac[i] = fac[i-1]*i;
    for(ll i = 3 ; i < 3000000 ; i++){
        if(check(i)==i) sum += i;
    }
    cout << sum;
}
