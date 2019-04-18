#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll N = 10000000;
const ll MOD = 1e18;

ll gcd(ll a, ll b){
    return a%b?gcd(b,a%b):b;
}

int main(){
    /*
    for(int i = 1 ; i < 10 ; i++){
        int g = 0;
        for(int j = 1 ; j < 1000 ; j++){
            g = max(g, gcd(j*j+i*i, 2*j+1));
        }
        cout << i << ' ' << g << endl;
    }*/
    // we find pattern 4*k^2 + 1 is the maximum gcd
    // it means we just find the maximum prime which
}
