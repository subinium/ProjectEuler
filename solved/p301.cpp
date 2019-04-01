#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 30;

int main(){
  int ans = 0;
  for(ll i = 1 ; i <= 1<<30 ; i++){
    ans += !(i^(i*2)^(i*3));
  }
  cout << ans;
}
