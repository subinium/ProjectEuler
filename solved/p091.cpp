#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second

int SZ = 50;

int sq(int a){
  return a*a;
}

int dist(pii a, pii b){
  return sq(a.fi-b.fi) + sq(a.se-b.se);
}

bool tri_ck(pii a, pii b, pii c){
  vector<int> v;
  v.push_back(dist(a,b));
  v.push_back(dist(a,c));
  v.push_back(dist(b,c));
  sort(v.begin(), v.end());
  return v[0] && (v[0] + v[1] == v[2]);
}

int main(){
  vector<pii> v;
  for(int i = 0 ; i <= SZ ; i++){
    for(int j = 0 ; j <= SZ ; j++){
      v.push_back(pii(i,j));
    }
  }
  int tot = 0;
  for(int i = 1 ; i < v.size(); i++){
    for(int j = i+1 ; j < v.size() ; j++){
      tot += tri_ck(v[0],v[i],v[j]);
    }
  }
  cout << tot;
}
