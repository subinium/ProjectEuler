#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int rm[128];
int mi[128][128];

int rtoi(string s){
  int ret = 0;
  for(int i = 0 ; i < s.size() ; i++){
    ret += rm[s[i]];
    if(i!=s.size()-1){
      ret -= 2*rm[s[i]] * mi[s[i]][s[i+1]];
    }
  }
  return ret;
}

int itor_cnt(int n){
  int ret = 0;
  for(int i = 0 ; i < 4 ; i++){
    int r = n%10;
    if((r==4||r==9)&&i!=3) ret += 2;
    else if(r<5) ret += r;
    else ret += r-4;
    n /= 10;
  }
  return ret;
}

int process(){
  string s; cin >> s;
  return s.size() - itor_cnt(rtoi(s));
}

void init(){
  int num[7] = {1,5,10,50,100,500,1000};
  string s = "IVXLCDM";
  for(int i = 0 ; i < 7 ; i++){
    rm[s[i]] = num[i]; 
  }
  mi['I']['V'] = mi['I']['X'] = 1;
  mi['X']['L'] = mi['X']['C'] = 1;
  mi['C']['D'] = mi['C']['M'] = 1;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("p089_roman.txt","r",stdin);
  init();
  int tc = 10000;
  int ans = 0;
  while(tc--){
    ans += process();
  }
  cout << ans;
}
