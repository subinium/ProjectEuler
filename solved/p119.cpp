#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll sum(ll n){
    ll ret = 0;
    while(n){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main(){
    priority_queue<pll,vector<pll>, greater<pll> > pq;
    for(int i = 2 ; i <= 99 ; i++){
        pq.push({i*i,i});
    }
    int flag = 0;
    while(flag < 30){
        auto tp = pq.top(); pq.pop();
        if(sum(tp.first)==tp.second){
            flag++;
            cout << flag << endl;
            cout << tp.first << endl;
        }
        pq.push({tp.first*tp.second, tp.second});
    }
}
