#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e8;
bool p[SZ];

void era(){
  p[0]=p[1]=true;
  for(int i = 2 ; i < SZ ; i++){
    if (p[i]) continue;
    for(int j = 2*i ; j < SZ ; j+=i){
      p[j] = true;
    }
  }
}

int ck[7];

bool f(int len, int same){
  int add_sz = 0;
  for(int i = len-1 ; i >=0 ; i--){
    add_sz = add_sz*10 + ck[i];
  }
  int SZ_TMP = 1;
  for(int i = 0 ; i < len ; i++) SZ_TMP *= 10;
  for(int i = SZ_TMP/10 ; i < SZ_TMP ; i++){
    if(p[i]) continue;
    set<int> s;
    int ii = i;
    int flag = -1;
    for(int j = 0 ; j < len ; j++){
      if(ck[j]==1){
        s.insert(ii%10);
        flag = ii%10;
      }
      ii /= 10;
    }
    if(s.size()==1&&flag<=2){
      vector<int> candi;
      for(int j = 0 ; j <= 9-flag ; j++){
        if(!p[i+j*add_sz]){
          candi.push_back(i+j*add_sz);
        }
      }
      if(candi.size()==8){
        for(int j = 0 ; j < 8 ; j ++)
          cout << candi[j] << endl;
        return true;
      }
    }
  }  
  return false;
}

int main(){
  era();
  for(int i = 4 ; ; i++){ // 자릿수
    int ok = 0;
    for(int j = 1 ; j <= i ; j++){ // 체크 개수
      memset(ck,0,sizeof(ck));
      for(int k = 0 ; k < j ; k++) ck[k] = 1;
      do{
        if(f(i,j)){
          cout << "I found it in len : " << i << endl;
          ok = 1;
        }
      }while(prev_permutation(ck,ck+i));
    }
    if(ok) break;
  }  
}
