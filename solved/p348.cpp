#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1e9;

int arr[MX];
vector<ll> sq, cb;

int palin(int n){
  vector<int> v;
  while(n){
    v.push_back(n%10);
    n/=10;
  }
  for(int i = 0 ; i*2 < v.size() ; i++) if(v[i]!=v[v.size()-i-1]) return false;
  return true;
}

int main(){
  for(int i = 1 ; i*i < MX ; i++) sq.push_back(i*i);
  for(int i = 1 ; i*i*i < MX ; i++) cb.push_back(i*i*i);
  for(int i = 0 ; i < sq.size() ; i++){
    for(int j = 0 ; j < cb.size() ; j++){
      if(sq[i]+cb[j]<MX) arr[sq[i]+cb[j]]++;
    }
  }
  int cnt = 0;
  ll tot = 0;
  for(int i = 1 ; i < MX ; i++){
    if(arr[i]==4&&palin(i)){
      cnt++;
      tot += i;
      cout << i << endl;
    }
    if(cnt==5) break; 
  }
  cout << tot << endl;
}

// 6s
