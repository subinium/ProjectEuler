#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool isPalin(string s){
    for(int i = 0 ; i * 2 < s.size() ; i++){
        if(s[i]!=s[s.size()-i-1]) return false;
    }
    return true;
}

string itox(int n, int x){
    string ret;
    while(n){
        ret += '0' + n%x;
        n /= x;
    }
    return ret;
}


int main(){
    ll ans = 0;
    for(int i = 1 ; i <= 1000000 ; i+=2){
        if(isPalin(itox(i,10)) && isPalin(itox(i,2))) ans += (ll)i;
    }
    cout << ans;
}
