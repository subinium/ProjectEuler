#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll SZ = 59049; // 3 ^ 11
const int R = 20, MOD = 11;

ll dp[R+1][SZ][11];

int to3(vi v){
    int ret = 0;
    for(int i = 9 ; i >= 0 ; i--){
        ret = ret*3 + v[i];
    }
    return ret;
}

vi tov(int n){
    vi ret;
    for(int i = 0 ; i <= 9 ; i++){
        ret.push_back(n%3);
        n /= 3;
    }
    return ret;
}

int main(){
    for(int i = 1 ; i < 10 ; i++){
        vi tmp(10);
        tmp[i]++;
        dp[1][to3(tmp)][i]++;
        tmp[i]--;
    }
    for(int i = 1 ; i <= 19 ; i++){
        for(int j = 0 ; j < SZ ; j++){
            vi tmp = tov(j);
            for(int k = 0 ; k < 10 ; k++){
                if(tmp[k]<2){
                    tmp[k]++;
                    for(int x = 0 ; x < 11 ; x++){
                        int idx = to3(tmp);
                        dp[i+1][idx][(x*10+k)%MOD] += dp[i][j][x];
                    }
                    tmp[k]--;
                }
            }
        }
    }

    cout << dp[R][SZ-1][0];
}
