#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll arr[101][101];

int main(){
  arr[0][0] = 1;
  for(int i = 1 ; i <= 100 ; i++){
    for(int j = 1 ; j <= i ; j++){
      for(int k = 0 ; k <= j ; k++){
        arr[i][j] += arr[i-j][k];
      }
    }
  }  
  ll ans = 0;
  for(int i = 1 ; i <= 100 ; i++) ans += arr[100][i];
  cout << ans-1;
}
