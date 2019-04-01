#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1e7;

int arr[SZ];

void era(){
  for(int i = 2 ; i < SZ ; i++){
    for(int j = i ; j < SZ ; j+= i){
      arr[j] ++;
    }
  }
}

int main(){
  era();
  int ans = 0;
  for(int i = 2 ; i < SZ-1 ; i++){
    ans += arr[i]==arr[i+1];
  }
  cout << ans;

}
