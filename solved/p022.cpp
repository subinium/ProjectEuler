#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

char arr[1000000];

int main(){
  freopen("p022_names.txt","r",stdin);
  gets(arr);
  int len = strlen(arr);
  int flag = 0, idx = 0;
  int ans = 0, sum = 0;
  string s = "";
  vector<pair<string, int> > v;
  for(int i = 0 ; i < len ; i++){
    if(arr[i]=='\"'){
      if(flag == 0) s = "", sum = 0, idx++;
      else{
        //sum += idx * sum;
        v.push_back(make_pair(s,sum));
      }
      flag ^= 1;
    }
    else{
      sum += arr[i]-'A'+1;
      s += arr[i];
    }
  }
  sort(v.begin(),v.end());
  for(int i = 0 ; i < v.size(); i++){
    cout << v[i].first << ' ' << v[i].second << '\n';
    ans += v[i].second * (i+1); 
  }
  cout << ans;
}
