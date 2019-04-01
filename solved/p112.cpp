#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool ck(int n){
  int f = n%10;
  int ff = f;
  n /= 10;
  bool tf = true, ttf = true;
  while(n){
    int s = n % 10;
    if(s > f) tf = false;
    if(s < ff) ttf = false;
    f = ff = s;
    n /= 10;
  }
  return tf||ttf;

}

int main(){
  int tot = 0;
  for(int i = 1 ; ; i++){
    if(ck(i)) tot++;
    if(tot*100<=i){
      cout << i << endl;
      return 0;
    }
  }
}
