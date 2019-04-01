#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int arr[9][9], ans;
bool chk_row[9][10], chk_col[9][10], chk_cell[9][10];

int cell_num(int r, int c){
  return 3*(r/3) + c/3;
}

void init(){
  string s, t; cin >> s >> t;
  memset(chk_row,false,sizeof(chk_row));
  memset(chk_col,false,sizeof(chk_col));
  memset(chk_cell,false,sizeof(chk_cell)); 
  
  for(int i = 0 ; i < 9 ; i++){
    for(int j = 0 ; j < 9 ; j++){
      int x; scanf("%1d",&x);
      arr[i][j] = x;
      chk_row[i][x] = true;
      chk_col[j][x] = true;
      chk_cell[cell_num(i, j)][x] = true;
    }
  }
}

void solve(){
  int r = -1, c = -1;
  for(int i = 0 ; i < 9 ; i++){
    for(int j = 0 ; j < 9; j++){
      if(!arr[i][j]){
        r = i, c = j;
        break;
      }
    }
    if(r!=-1) break;
  }
  if(r == -1){
    ans += arr[0][0] * 100 + arr[0][1] * 10 + arr[0][2];
  }

  for (int x = 1; x <= 9; x++) {
    if (!chk_row[r][x] && !chk_col[c][x] && !chk_cell[cell_num(r, c)][x]) {
      chk_row[r][x] = chk_col[c][x] = chk_cell[cell_num(r, c)][x] = true;
      arr[r][c] = x;
      solve();
      arr[r][c] = 0;
      chk_row[r][x] = chk_col[c][x] = chk_cell[cell_num(r, c)][x] = false;
    }
  }
}

int main(){
  freopen("p096_sudoku.txt","r",stdin);
  int tc = 50;
  while(tc--){
    init();
    solve();
  }
  cout << ans;
}
