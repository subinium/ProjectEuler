#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ  = 1e7;

ll arr[SZ];

void era(){
  for(ll i = 1 ; i < SZ ; i++) arr[i] = i;
  for(ll i = 2 ; i < SZ ; i++){
    if(arr[i]!=i) continue;
    for(ll j = i ; j < SZ ; j+= i){
      arr[j] = arr[j]/i*(i-1); 
    }
  }
}

bool ck(ll n){
  ll a[10]={0,}, b[10]={0,};
  ll pi = arr[n];
  while(n){
    a[n%10]++;
    n/=10;
  }
  
  while(pi){
    b[pi%10]++;
    pi/=10;
  }
  for(int i = 1 ; i < 10 ; i++) if(a[i]!=b[i]) return false;
  return true;
}

int main(){
  era();
  ll mo = 1, so = SZ;
  for(ll i = 2 ; i < SZ ; i++){
    if(ck(i)){
      if(i*mo<so*arr[i]){
        
        mo = arr[i];
        so = i;
      }
    }
  }
  cout << so;
}
