#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  freopen("p099_base_exp.txt","r",stdin);
  long double mx = 0;
  int flag = 0;
  for(int i = 1 ; i <= 1000 ; i++){
    long double a, b; char c; cin >> a >> c >> b;
    //cout << a << ' ' << b << endl;
    a = b*log(a);
    if(a>mx){
      mx = a;
      flag = i;
    }
  }
  cout << flag;
}
