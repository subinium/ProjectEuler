#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool isprime(int n){
  if(n==1) return false;
  for(int i = 2 ; i*i <= n ; i++) if(n%i==0) return false;
  return true;
}

int main(){
  int tot = 1;
  int pcnt = 0;
  for(int i = 3 ; ; i+=2){
    for(int j = 0 ; j < 4 ; j++){
      if(isprime(i*i-j*(i-1))) pcnt++;
    }
    tot += 4;
    if(10*pcnt<tot){
      cout << i;
      return 0;
    }
  }
}
