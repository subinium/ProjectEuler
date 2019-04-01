#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 100;

vector<int> dart(21);

int main(){
  int ans = 0;
  for(int i = 1 ; i <= 20 ; i++) dart[i-1] = i;
  dart[20] = 25;
  for(int sum = 2 ; sum < SZ ; sum++){
    for(auto i: dart){
      if(i*2==sum){
        ans++;
      }
      set<set<pii> > st;
      for(auto j : dart){
        for(auto k : dart){
          for(int jc = 1 ; jc <= 3 ; jc++){
            if(j==25&&jc==3) break;
            if(i*2+j*jc==sum){
              set<pii> s;
              s.insert({j,jc});
              st.insert(s);
            }
            for(int kc = 1 ; kc <= 3 ; kc++){
              if(k==25&&kc==3) break;
              if(i*2 + j*jc + k*kc == sum){
                set<pii> s;
                s.insert({j,jc});
                s.insert({k,kc});
                st.insert(s);
              }
            }
          }
        }
      }
      ans += st.size();
    }

  }
  cout << ans;
}
