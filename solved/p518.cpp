#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e8;

bool arr[SZ];

ll gcd(ll a, ll b){
    return a%b?gcd(b,a%b):b;
}

void era(){
    arr[0] = arr[1] = true;
    for(ll i = 2 ; i < SZ ; i++){
        if(arr[i]) continue;
        for(ll j = 2*i ; j < SZ ; j+= i){
            arr[j] = true;
        }
    }
}

int main(){
    era();
    ll ans = 0;
    for(ll d = 1 ; d*d <= SZ ; d++){
        for(ll a = 1 ; a*d*d <= SZ ; a++){
            if(!arr[a*d*d-1]){
                for(ll k = d+1 ; a*k*k <= SZ ; k++){
                    ll b = a*d*k-1;
                    ll c = a*k*k-1;
                    if(!arr[b]&&!arr[c]&&gcd(d,k)==1){
                        ans += a*d*d-1 + b + c;
                        //cout << a*d*d-1 << ' ' << b << ' ' << c << endl;
                    }
                }
            }
        }
    }
    cout << ans;
}
