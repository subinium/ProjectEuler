#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second

int area(pii a, pii b, pii c){
  return abs(a.fi*b.se+b.fi*c.se+c.fi*a.se - a.fi*c.se-c.fi*b.se-b.fi*a.se);
}

int process(){
  vector<pii> p;
  for(int i = 0 ; i < 3 ; i++){
    int a, b; scanf("%d,%d,",&a,&b);
    p.push_back(pii(a,b));
  }
  p.push_back(pii(0,0));
  return ( area(p[0],p[1],p[3]) + area(p[1],p[2],p[3]) + area(p[0],p[2],p[3]) ) == area(p[0],p[1],p[2]);

}

int main(){
  freopen("p102_triangles.txt","r",stdin);
  int tc = 1000;
  int ans = 0;
  while(tc--){
    ans += process();
  }
  cout << ans;
}
