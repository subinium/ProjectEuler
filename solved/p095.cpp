#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e6+1;

int arr[SZ], ck[SZ];
int mx_cnt, ans;

void era(){
  for(int i = 1 ; i < SZ ; i++){
    for(int j = 2*i ; j < SZ ; j+=i){
      arr[j] += i;
    }
  }
}

int main(){
  era();
  int flag = 0;
  for(int i = 2 ; i < SZ ; i++){
    int idx = i, cnt = 0;
    flag++;
    do{
      if(ck[idx]==flag) break;
      ck[idx] = flag;
      idx = arr[idx];
      if(idx==0|| idx >= SZ || idx < i){
        cnt = -1;
        break;
      } 
      cnt++;
    }while(idx!=i);
    if(idx==i && cnt > mx_cnt){
      mx_cnt = cnt;
      ans = i;
    } 
  }
  cout << ans;
}
