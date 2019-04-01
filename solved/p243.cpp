#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MX = 1e9;
ll arr[MX];

void phi(){
  for(ll i = 2 ; i < MX ; i++) arr[i] = i;
  for(ll i = 2 ;i < MX ; i++){
    if(arr[i]!=i) continue;
    for(ll j = i ; j < MX ; j+=i){
      arr[j] = arr[j] / i * (i-1);
    }
  }
  
}

int main(){
  phi();
  ll mo = 94744, so = 15499;
  //ll mo = 10, so = 4;
  for(ll i = 2 ; ; i++){
    if(arr[i]==i-1) continue;
    if(arr[i]*mo < so*(i-1)){
      cout << arr[i] << endl;
      cout << i ;
      return 0;
    }
  }
}

// 2m 17s
