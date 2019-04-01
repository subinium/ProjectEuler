#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 16;
const int len = 10;
int a[len];

string arr[11];

string ans;

string mx(string a, string b){
  if(a.size()==b.size()) return a>b?a:b;
  return a.size()>b.size()?a:b;
}

int main(){
  for(int i = 0 ; i < 10 ; i++) a[i] = i+1;
  for(int i = 0 ; i < 10 ; i++) arr[i] = '0'+i;
  arr[10] = "10";
  do{
    bool ck = true;
    set<int> s;
    for(int i = 0 ; i < 5 ; i++){
      s.insert(a[i*2]+a[i*2+1]+a[(i*2+3)%10]); 
      if(a[0]>a[2*i]) ck = false;
      if(!ck) break;
    }
    
    if(ck&&s.size()==1){
      string tmp;
      for(int i = 0 ; i < 5 ; i++){
        tmp += arr[a[i*2]] + arr[a[i*2+1]] + arr[a[(i*2+3)%10]];
      }
      if(tmp.size()==16) ans = mx(tmp, ans);
    }

  }while(next_permutation(a,a+10));
  cout << ans;
}
