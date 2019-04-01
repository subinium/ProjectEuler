#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 6e4;
const ll MOD = 1e6;
ll arr[SZ][SZ];
ll tot[SZ];

int main(){
  arr[1][1] = 1;
  for(int i = 2 ; i < SZ ; i++){
    arr[i][1] = arr[i][i] = 1;
    tot[i] = 2;
    for(int j = 2 ; j < i ; j++){
      arr[i][j] = (arr[i-1][j-1]+arr[i-j][j]) % MOD; 
      tot[i] = (tot[i] + arr[i][j]) % MOD;
    }
    if(tot[i]%MOD==0){
      cout << i << endl;
      return 0;
    }
  }
}

// 3m 56s
