#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// pell equation
// Diophantine Quadratic Equation
const ll SZ = 1e12;

int main(){
  ll blue = 3, tot = 4; 
  while(tot <= SZ ){
    ll bt = blue, tt = tot;
    blue = 3*bt+2*tt-2;
    tot = 4*bt+3*tt-3;
  }
  cout << blue;
}
