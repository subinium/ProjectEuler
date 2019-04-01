#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int arr[105][105];

int main(){
  freopen("p067_triangle.txt","r",stdin);
  for(int i = 1 ; i <= 100 ; i++){
    for(int j = 1 ; j <= i ; j++){
      cin >> arr[i][j];
    }
  }
  for(int i = 1 ; i <= 100 ; i++){
    for(int j = 1; j <= i ; j++){
      arr[i][j] = arr[i][j] + max(arr[i-1][j],arr[i-1][j-1]);
    }
  }
  int ans = 0;
  for(int i = 1 ; i <= 100 ; i++){
    ans = max(ans, arr[100][i]);
  }
  cout << ans;
}
