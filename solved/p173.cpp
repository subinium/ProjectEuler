#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1000000;
ll f(int n){
  int cnt = 0;
  for(int i = 1 ; i*i < n ; i++){
    if(n%i==0)cnt++;
  }
  return cnt;
}

int main(){
  int n;
  ll tot = 0;
  for(int i = 4 ; i <= SZ ; i+=4){
    int num = i/4;
    tot += f(num);
  }
  cout << tot;
}
