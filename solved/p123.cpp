#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 3e6;
const ll MX = 1e10;

bool arr[SZ];
vector<ll> p;

void era(){
    p.push_back(0);
    for(ll i = 2 ; i < SZ ; i ++){
        if(arr[i]) continue;
        p.push_back(i);
        for(ll j = i*i ; j < SZ ; j += i){
            arr[j] = true;
        }
    }
}

ll f(ll i){
    return 2*i*p[i];
}

int main(){
    era();
    for(int i = 1 ; ; i+=2){
        if(p[i]*p[i]<MX) continue;
        if(f(i)>=MX){
            cout << i;
            return 0;
        }
    }
}
