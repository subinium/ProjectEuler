#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll SZ = 1500000;

int arr[SZ+1];

ll gcd(ll a, ll b){
  return a%b?gcd(b,a%b):b;
}

int main(){
  int len = sqrt(SZ/2);
  for(ll i = 2 ; i <= len ; i++){
    for(ll j = 1; j < i ; j++){
      if((i+j)%2 && gcd(i,j)==1){
        // 피타고라스 필요충분 조건
        ll a = i*i+j*j;
        ll b = i*i-j*j;
        ll c = 2*i*j;
        ll tot = a + b + c;
        ll flag = 1;
        // 정수배
        while(flag * tot<=SZ){
          arr[flag * tot]++;
          flag++;
        }
      }
    }
  }
  int ans = 0;
  for(int i = 1 ; i <= SZ ; i++){
    ans += arr[i]==1;
  }
  cout << ans;
}
