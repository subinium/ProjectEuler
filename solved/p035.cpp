#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1e6;

bool pr[SZ+5];

void era(){
    for(int i = 2 ; i <= SZ ; i++){
        if(pr[i]) continue;
        for(int j = 2*i ; j <= SZ ; j+= i){
            pr[j] = true;
        }
    }
}

int nxt(int n, int flag){
    return (n%10)*flag + n/10;
}

int main(){
    era();
    int flag = 1, tot = 0;
    for(int i = 2 ; i <= SZ ; i++){
        if(pr[i]) continue;
        if(i>=flag*10) flag *= 10;
        int st = i;
        int cnt_tmp = 0;
        do{
            pr[st] = true;
            st = nxt(st, flag);
            cnt_tmp++;
        }while(st!=i && !pr[st]);
        if(st == i) tot += cnt_tmp;
    }
    cout << tot << endl;
}
