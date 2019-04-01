#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e10;

int main(){
  ll ans = 28433;
  for(int i = 0 ; i < 7830457 ; i++){
    ans *= 2;
    ans %= MOD;
  }
  cout << ans + 1 << endl;
}
