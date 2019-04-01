#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cnt[128][3];
int key[3];
int main(){
  freopen("p059_cipher.txt","r",stdin);
  string s; cin >> s;
  s += ',';
  vector<int> v;
  int tmp = 0;
  for(int i = 0 ; i < s.size() ; i++){
    if(s[i]==','){
      v.push_back(tmp);
      tmp = 0;
    }
    else tmp = tmp*10 + s[i]-'0';
  }
  for(int i = 0 ; i < v.size() ; i++){
    cnt[v[i]][i%3]++;
  } 
  for(int i = 0 ; i < 128 ; i++){
    for(int j = 0 ; j < 3 ; j++){
      if(cnt[i][j]>60){
        cout << (char)i << endl;
        key[j] = i-'A'+'a';
      }
    }
  }
  int tot = 0;
  for(int i = 0 ; i < v.size() ; i++){
    cout << (char)(v[i]^key[i%3]);
    tot += (v[i]^key[i%3]);
  }
  cout << tot;

}
