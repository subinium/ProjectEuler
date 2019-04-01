#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  double ans = 0;
  double p = 1.0;
  for(int i = 0; i < 50 ; i++){
    ans += (double)(1-pow((1-p),32));
    p /= 2.0;
  }
  printf("%.11lf",ans);
}
