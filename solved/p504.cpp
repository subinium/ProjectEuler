#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 100;

int sq[4*SZ*SZ];
int cnt[SZ+1][SZ+1];

int gcd(int a, int b){
  return a%b?gcd(b,a%b):b;
}

int main(){
  for(int i = 1 ; i < 2*SZ ; i++) sq[i*i] = 1;
  for(int i = 2 ; i <= SZ ; i++){
    for(int j = 2 ; j <= SZ ; j++){
      cnt[i][j] = ((i-1)*(j-1) - (gcd(i,j)-1)) / 2;
    }
  }
  int ans = 0;
  for(int a = 1 ; a <= SZ ; a++){
    for(int b = 1 ; b <= SZ ; b++){
      for(int c = 1 ; c <= SZ ; c++){
        for(int d = 1 ; d <= SZ ; d++){
          int tot = a + b + c + d - 3 + cnt[a][b]+ cnt[b][c] + cnt[c][d] + cnt[d][a];
          if(sq[tot]) ans++;
        }
      }
    }
  }
  cout << ans;
}
