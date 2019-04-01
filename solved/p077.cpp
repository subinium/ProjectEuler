#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e4;

vector<int> p;

bool arr[SZ];

void era(){
  for(int i = 2 ; i < SZ ; i++){
    if(arr[i]) continue;
    p.push_back(i);
    for(int j = 2*i ; j < SZ ; j+= i){
      arr[j] = true;
    }
  }

}

int dp[SZ][1300];
int tot[SZ];

int main(){
  era();
  dp[0][p.size()-1] = 1;
  
  for(int i = 2 ; i < SZ ; i++){
    for(int j = 0 ; j < p.size() ; j++){
      for(int k = 0 ; k <= j ; k++){
        if(i-p[k]<0) break;
        dp[i][k] += dp[i-p[k]][j];
        tot[i] += dp[i-p[k]][j]; 
      }
    }
    if(tot[i]>5000){
      cout << tot[i] << endl;
      cout << i << endl;
      return 0;
    }
  }
  
}
