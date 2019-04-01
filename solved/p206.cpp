#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans;
string s = "1_2_3_4_5_6_7_8_9";

int f(ll n){
  string ret = "";
  for(int i = 0 ; i < 17 ; i++){
    if(i%2==0) ret += n%10+'0';
    else ret += '_';
    n /= 10;
  }
  return ret == s;
}


int main(){
  reverse(s.begin(),s.end());
  int ans = 0;
  for(ll i = 100000000 ; i <= 400000000 ; i++){
    if((i*i)%10!=9) continue;
    if(i*i>=2e16) break;
    if(f(i*i)){
      //ans ++;
      cout << i*i << ' ' << i << endl;
    }
  }
  //cout << ans;
}
