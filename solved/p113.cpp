#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 100;

ll incr[100][10];
ll decr[100][10];

int main(){
  for(int i = 1 ; i <= 9 ; i++){
    incr[1][i] = decr[1][i] = 1;
  }
  for(int i = 2 ; i <= SZ ; i++){
    for(int j = 0 ; j <= 9 ; j++){
      for(int k = j ; k <= 9 ; k++){
        incr[i][k] += incr[i-1][j];
      }
    }
    for(int j = 0 ; j <= 9 ; j++){
      for(int k = 0 ; k <= j ; k++){
        decr[i][k] += decr[i-1][j];
      }
    }
  }
  ll tot = 0;
  for(int i = 1 ; i <= SZ ; i++){
    for(int j = 0 ; j < 10 ; j++){
      tot += incr[i][j] + decr[i][j];
    }
  }
  cout << tot - 9ll*(ll)SZ << endl;
}
