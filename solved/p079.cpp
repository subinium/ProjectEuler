#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int s[10];
int d[10];

bool ck(){
  for(int i = 0; i < 10 ; i++) if(d[i]!=-1) return false;
  return true;
}

int main(){
  freopen("p079_keylog.txt","r",stdin);
	memset(d,-1,sizeof(d));
  for(int i = 0 ; i < 50 ; i++){
		string tmp; cin >> tmp;
		for(int i = 0 ; i < 3 ; i++){
      d[tmp[i]-'0'] = 1;
      for(int j = i+1 ; j < 3 ; j++){
        s[tmp[j]-'0'] |= 1<<(tmp[i]-'0');
      }
    }
	}
  for(int i = 0 ; i < 10 ; i ++) cout << d[i] << endl;
  int key = 0;
  while(!ck()){
    int mx = -1;
    for(int j = 0 ; j < 10 ; j++){
      if(d[j]==-1) continue;
      //cout << s[j].size() << ' ' << mc < end;
      if((key&s[j])==s[j]){
        mx = j;
        break;
      }
    }
    cout << mx;
    if(mx!=-1) d[mx]=-1, key|=1<<mx;
  }
  for(int i = 0 ; i < 10 ; i++) if(d[i]!=-1) cout << i << endl;
}
