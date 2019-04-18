#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> st[105];
int ck[105];

void f(int a, int cnt){
    for(int b = 2 ; b <= 100 ; b++){
        st[a].insert(cnt*b);
    }
}

int main(){
    for(int a = 2 ; a <= 100 ; a++){
        int cnt = 1;
        if(ck[a]) continue;
        for(int aa = a ; aa <= 100 ; aa*=a ){
            f(a,cnt++);
            ck[aa] = true;
        }
    }
    int sum = 0;
    for(int a = 2 ; a <= 100 ; a++){
        sum += st[a].size();
    }
    cout << sum << endl;

}
