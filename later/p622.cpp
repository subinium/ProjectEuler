#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1e6;

int arr[MX];

int gcd(int a, int b){
  return a%b?gcd(b,a%b):b;
}

int main(){
  ll ans = 0;
  for(int sz = 2 ; sz < MX ; sz+=2){
    for(int i = 0 ; i < sz ; i++){
      if(i < sz/2){
        arr[i] = i*2;
      }
      else arr[i] = (i-sz/2)*2 + 1;
    }
    int lcm = 1;
    for(int i = 0 ; i < sz ; i++){
      //if(arr[i]==0) continue;
      int f = i;
      int cnt = 1;
      while(i!=arr[f]){
        //int tmp = f;
        cnt++;
        f = arr[f];
        //arr[tmp] = 0;
      }
      lcm = lcm/gcd(lcm,cnt)*cnt;
      if(lcm>60) break;
    }
    //cout << sz << ' ' << lcm << endl;
    if(lcm==60){
      ans += (ll)sz;
      //cout << sz << endl;
    }
  }
  cout << ans << endl;

}
