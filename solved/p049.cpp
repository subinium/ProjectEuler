#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int sz = 1e4;
int arr[sz];
vector<int> v;

string is(int n){
  string s = "";
  while(n){
    s += '0' + n%10;
    n /= 10;
  }
  sort(s.begin(),s.end());
  return s;
}

bool cmp(int n, int m){
  return is(n)==is(m);
}

int main(){
  for(int i = 2 ; i < sz ; i++){
    if(arr[i]) continue;
    if(i>1000) v.push_back(i);
    for(int j = 2*i ; j < sz ; j+=i){
      arr[j] = 1;
    }
  }
  for(int i = 0 ; i < v.size() ; i++){
    for(int j = i+1 ; j < v.size() ; j++){
      ll k = v[j]*2-v[i];
      if(cmp(v[i],v[j])&&k<10000&&!arr[k]&&cmp(v[i],k)){
        cout << v[i] << v[j] << k << endl;
      }
    }
  }

}
