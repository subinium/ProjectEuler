#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int arr[81][81];

int main(){
  freopen("p081_matrix.txt","r",stdin);
  int n = 80;
  for(int i = 1;  i<= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      scanf("%d,",&arr[i][j]);
      if(i==1) arr[i][j] += arr[i][j-1];
      else if(j==1) arr[i][j] += arr[i-1][j];
      else arr[i][j] += min(arr[i-1][j],arr[i][j-1]);
    }
    //cout << '\n';
  }
  cout << arr[n][n];
}
