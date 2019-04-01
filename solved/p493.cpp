#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  // 7* (1 - 60c20 / 70c20)
  double ans = 1;
  for(int i = 0 ; i < 20 ; i++){
    ans *= (double)(60-i)/(70-i);
  }
  printf("%.9lf",7*(1-ans));
}
