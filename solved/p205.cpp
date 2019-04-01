#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double pyra[10][37], cub[7][37];

int main(){
  pyra[0][0] = cub[0][0] = 1.0;
  for(int i = 0 ; i < 9 ; i++){
    for(int j = 0 ; j < 33 ; j++){
      for(int k = 1 ; k <= 4 ; k++){
        pyra[i+1][j+k] += pyra[i][j] / 4.0;
      }
    }
  }
  for(int i = 0 ; i < 6 ; i++){
    for(int j = 0 ; j < 31 ; j++){
      for(int k = 1 ; k <= 6 ; k++){
        cub[i+1][j+k] += cub[i][j] / 6.0;
      }
    }
  }
  double ans = 0;
  for(int i = 1 ; i <= 36 ; i++){
    for(int j = 1 ; j < i ; j++){
      ans += pyra[9][i] * cub[6][j];
    }
  }
  printf("%.7lf",ans);
}
