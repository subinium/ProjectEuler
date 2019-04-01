#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

multiset<multiset<int> > s;

multiset<int> msi(ll n){
  ll ii = n*n*n;
  multiset<int> m;
  while(ii){
      m.insert(ii%10);
      ii /= 10;
  }
  return m;
}

int main(){
    int flag = 0;
    for(ll i = 2 ; i < 10000; i++){
        s.insert(msi(i));
        if(s.count(msi(i))==5){
            flag = i;
            break;
        }
    }
    set<multiset<int> > f;
    for(ll i = 2 ; i < 10000 ; i++){
      f.insert(msi(i));
      if(f.count(msi(flag))){
        cout << i*i*i << endl;
        return 0;
      }
    }
}
