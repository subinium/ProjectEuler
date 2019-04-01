#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 40;
const int RTIME = 10000000;

int mono[SZ], cnt[SZ];
int CC[3] = {2,17,33}, CH[3] = {7,22,36};

int CC_RAND(int n){
    int seed = rand()%16;
    if(seed==0) return 0;
    if(seed==1) return 10;
    return n;
}

int CH_RAND(int n){
    int seed = rand()%16;
    int way[6] = {0,10,11,24,39,5};
    if(seed<6) return way[seed];
    if(seed<8){
        if(seed == 7) return 15;
        if(seed == 22) return 25;
        if(seed == 36) return 5;
        return n;
    }
    if(seed==8){
        if(n==22) return 28;
        else return 12;
    }
    if(seed==9) return n-3;
    return n;
}

void init(){
    for(int i = 0 ; i < 3 ; i++){
        mono[CC[i]] = 1;
        mono[CH[i]] = 2;
    }
}

void game(){
    int pos = 0;
    int db = 0;
    for(int i = 0 ; i < RTIME ; i++){
        int d1 = rand()%4 + 1, d2 = rand()%4 + 1;
        pos = (pos+d1+d2) % SZ;
        if(d1==d2) db++;
        else db = 0;
        if(db==3){
            pos = 10; db = 0;
        }
        if(mono[pos]==1) pos = CC_RAND(pos);
        else if(mono[pos]==2) pos = CH_RAND(pos);
        else if(pos==30) pos = 10;
        cnt[pos]++;
    }
}

int main(){
    srand(time(NULL));
    init(); game();
    vector<pii> v;
    for(int i = 0 ; i < SZ ; i++){
        v.push_back({cnt[i],i});
    }
    sort(v.begin(),v.end(),greater<pii>());
    for(int i = 0 ; i < 3 ; i++){
        cout << v[i].second << ' ';
    }
}
