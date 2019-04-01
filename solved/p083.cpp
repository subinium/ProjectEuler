#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 80;
const int INF = 1e9;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

vector<pii> edge[SZ*SZ];
int arr[SZ][SZ], dist[SZ*SZ];

int scope_check(int i, int j){
  return i >= 0 && i < SZ && j >= 0 && j < SZ;
}

int idx(int i, int j){
  return i*SZ + j;
}

void dijkstra(){
    int st = 0;
    for (int i = 0; i <= SZ*SZ; i++) dist[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[st] = 0;
    pq.push(pii(0, st));
    while (!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        int x = tmp.second;
        int z = tmp.first;
        if (dist[x] < z) continue;
        for (int i = 0; i < edge[x].size(); i++) {
            int y = edge[x][i].second;
            if (dist[y] > z + edge[x][i].first) {
                dist[y] = z + edge[x][i].first;
                pq.push(make_pair(dist[y], y));
            }
        }
    }

}

int main(){
  freopen("p083_matrix.txt","r",stdin);
  for(int i = 0 ; i < SZ ; i++){
    for(int j = 0 ; j < SZ ; j++){
      //cin >> arr[i][j];
      scanf("%d,",&arr[i][j]);
    }
  }
  cout << arr[SZ-1][SZ-1] << endl;
  for(int i = 0; i < SZ ; i++){
    for(int j = 0 ; j < SZ ; j++){
      for(int k = 0 ; k < 4 ; k++){
        int ii = i+dx[k];
        int jj = j+dy[k];
        if(scope_check(ii,jj)){
          edge[idx(i,j)].push_back(make_pair(arr[ii][jj],idx(ii,jj)));
        }
      }
    }
  }
  dijkstra();
  //for(int i = 0 ; i < SZ*SZ ; i++) cout << dist[i] << endl;
  cout << dist[idx(SZ-1,SZ-1)] + arr[0][0];
}
