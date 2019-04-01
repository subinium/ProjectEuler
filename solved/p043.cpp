#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p[8] = {0,2,3,5,7,11,13,17};

bool ck(string s){
  for(int i = 1; i <= 7 ; i++){
    int tmp = 0;
    for(int j = 0 ; j <= 2 ; j++){
      tmp = tmp*10+(s[i+j]-'0');
    }
    if(tmp%p[i]) return false; 
  }
  return true;
}

ll si(string x){
  ll ret = 0;
  for(int i = 0 ; i < x.size() ; i++) ret = ret*10+(x[i]-'0');
  return ret;
}

int main(){
  ll ans = 0;
  string s = "9876543210";
  do{
    //cout << s << endl;
    if(ck(s)){
      //cout << s;
      //break;
      ans += si(s);
    }
  }while(prev_permutation(s.begin(),s.end()));
  cout << ans;
}
