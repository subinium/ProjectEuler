#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e8;
int arr[SZ];

ll power(ll n, int k){
  ll ret = 1;
  while(k--){
    ret *= n;
    if(ret>SZ) return 2*SZ;
  }
  return ret;
}

int main(){
  for(int i = 2 ; i < SZ ; i++){
    for(int j = 2*i ; j < SZ ; j+=i){
      arr[j]++;
    }
  }
  ll tot = 0;
  for(int i = 2 ; i < SZ ; i++){
    if(arr[i]==1||arr[i]==2){
      tot ++;
      //cout << i << endl;
    }
    if(arr[i]==0){
      if(power(i,3)<SZ){
        tot--;
        //cout << 1 << ' ' << power(i,3) << endl;
    
      }
    }
  }
  cout << tot;
}
