#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e4;
const int MX = 5e7;
int arr[SZ];
vector<ll> p, pp[3];

void era(){
    for(int i = 2 ; i < SZ ; i++){
        if(arr[i]) continue;
        p.push_back(i);
        for(int j = 2*i ; j < SZ ; j+=i){
            arr[j] = 1;
        }
    }
}

ll power(ll n, int k){
    ll ret = 1;
    while(k--) ret *= n;
    return ret;
}

int main(){
    era();
    ll ans = 0;
    for(int i = 2 ; i <= 4 ; i++){
        for(ll k : p){
            if(power(k,i)> MX) break;
            pp[i-2].push_back(power(k,i));
        }
    }
    set<ll> st;
    for(ll i : pp[0]){
        for(ll j : pp[1]){
            for(ll k : pp[2]){
                ll tmp = i+j+k;
                if(tmp > MX) continue;
                st.insert(tmp);


            }
        }
    }
    cout << st.size();
}
