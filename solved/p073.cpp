#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 12000;

int gcd(int a, int b){
  return a%b?gcd(b,a%b):b;
}

int main(){
  int ans = 0;
  for(int i = 4 ; i <= SZ ; i++){
    for(int j = i/3 ; j <= i/2 ; j++){
      if(gcd(i,j)!=1) continue;
      if(j*3>i&&j*2<i) ans++;
    }
  }
  cout << ans;
}
