#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e9;

int a[N+1];

int main(){
    int cnt = 0;
    for(int i = 2 ; i <=  N ; i++){
        if(a[i]) continue;
        for(int j = i ; j <= N ; j+=i){
            a[j] = i;
        }
    }
    for(int i = 1 ; i <= N ; i++){
        cnt += a[i] < 100;
    }
    cout << cnt;
}

// 28s
