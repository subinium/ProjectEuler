#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e5;

int arr[SZ+1];
vector<pii> p;

void era(){
    for(int i = 1 ; i <= SZ; i++) arr[i] = 1;
    for(ll i = 1 ; i <= SZ ; i ++){
        if(arr[i]==1){
            for(ll j = i ; j <= SZ ; j += i){
                arr[j]*=i;
            }
        }
        p.push_back(pii(arr[i],i));
    }
}


int main(){
    era();
    sort(p.begin(),p.end());
    int idx = 1e4;
    cout << p[idx-1].second;
}
