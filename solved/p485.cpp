#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

const int SZ = 1e8;
const int sz = 1e5;

int arr[SZ+1];
deque<pil> dq;

void era(){
    for(int i = 1 ; i <= SZ ; i++) arr[i] = 1;
    for(int i = 2 ; i <= SZ ; i++){
        if(arr[i]!=1) continue;
        for(int j = i ; j <= SZ ; j+=i){
            int cnt = 0, tmp = j;
            while(tmp%i==0){
                tmp /= i;
                cnt++;
            }
            arr[j] *= cnt+1;
        }
    }
}


int main(){
    ll tot = 0;
    era();
    for(int i = 1 ; i <= SZ ; i++){
        while(!dq.empty() && dq.back().second < (ll)arr[i]) dq.pop_back();
        dq.push_back(pil(i,(ll)arr[i]));
        if(i - dq.front().first >= sz) dq.pop_front();
        if(i>=sz) tot += dq.front().second;
    }
    cout << tot << endl;
}
