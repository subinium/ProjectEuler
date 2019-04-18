#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll sum = 1;
    for(ll i = 3 ; i <= 1001 ; i+=2){
        sum += (i*i)*4;
        sum -= (i-1)*6;
    }
    cout << sum;
}
