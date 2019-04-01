#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int arr[5000];
char s[200000];
int cnt = 0;

int main(){
  freopen("p042_words.txt","r",stdin);
  int flag = 1;
  while(flag*(flag+1)/2 < 5000){
    arr[flag*(flag+1)/2] = 1;
    flag++;
  }
  gets(s);
  int len = strlen(s);
  int f = 0, sum = 0;
  for(int i = 0 ; i < len ; i++){
    if(s[i]=='\"'){
      if(f==0){
        sum = 0;
      }
      else{
        if(arr[sum]) cnt++;
      }
      f ^= 1;
    }
    else{
      sum += s[i]-'A'+1;
    }
  }
  cout << cnt;
}
