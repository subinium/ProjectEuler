#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ll mo = 5, so = 2;
    for(ll i = 8 ; i <= 1e6 ; i++){
        
        ll tmo = i, tso = 3*i/7;
        if(i%7==0) tso--;
        if(so*tmo<tso*mo){
            mo = tmo;
            so = tso;
        }
    }
    cout<< so;
}
