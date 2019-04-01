#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e7;

ll arr[SZ+1];

void era_maxp(){
    for(ll i = 2; i <= SZ ; i++){
        if(arr[i]) continue;
        for(ll j = 2*i ; j <= SZ ; j+=i){
            ll tmp = i;
            while(j%tmp==0){
                tmp *= i;
            }
            arr[j] = max(arr[j],tmp/i);
        }
    }
}



int main(){
    era_maxp();
    ll ans = 0;
    for(ll i = 2 ; i <= SZ ; i++){
        if(arr[i]==0){
            ans += 1;
            continue;
        }
        int ck = 1;
        for(ll x = i-arr[i] ; x > 0 ; x -= arr[i] ){
            if(x*(x+1)%i==0){
                ans += x+1;
                ck = 0;
                break;
            }
            else if(x*(x-1)%i==0){
                ans += x;
                ck = 0;
                break;
            }
        }
        ans += ck;
    }
    cout << ans;
}
