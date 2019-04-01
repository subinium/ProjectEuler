#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 15;

int src= SZ*2, snk= SZ*2+1;
int c[33][33], w[33][33];

int ans;
int spfa(){
    vector<int> dist(32,1e9), in(32,0), p(32,-1);
    queue<int> q;
    q.push(src);
    in[src]=1; dist[src]=0;
    p[src]=src;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        in[cur]=0;
        for(int i=0;i<32;++i){
            if(c[cur][i]){
                if(dist[i]>dist[cur]+w[cur][i]){
                    dist[i]=dist[cur]+w[cur][i];
                    p[i]=cur;
                    if(!in[i]){
                        in[i]=1;
                        q.push(i);
                    }
                }
            }
        }
    }
    if(p[snk]==-1)return 0;
    for(int s=snk;s!=p[s];s=p[s]){
        c[p[s]][s]--;
        c[s][p[s]]++;
    }
    ans-=dist[snk];
    return 1;
}

int main(){
    for(int i=0;i<SZ;++i){
        c[src][i]=1;
        c[SZ+i][snk]=1;
        for(int j=0;j<SZ;++j){
            int x; cin >> x;
            w[i][SZ+j]=-x;
            w[SZ+j][i]=x;
            if(w[i][SZ+j]){
                c[i][SZ+j]=1;
            }
        }
    }
    while(spfa());
    cout << ans;
}
