#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int SZ = 5e8;

int arr[SZ+1];

void era(){
    for(int i = 1 ; i <= SZ ; i++) arr[i] = i;
    for(int i = 2 ; i <= SZ ; i++){
        if(arr[i]!=i) continue;
        for(int j = i ; j <= SZ ; j+=i){
            arr[j] = arr[j]/i*(i-1);
        }
    }
}

ll ans;

int main(){
    era();
    for(int i = 1 ; i <= SZ ; i+=2){
        ans += arr[i];
    }
    cout << ans;
}
