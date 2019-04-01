#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll SZ = 1e3;

int cycle_len(int n){
    if(n==1) return 0;
    int num = 9, ret = 0;
    while(num){
        num = (num*10+9)%n;
        ret++;
    }
    return ret;
}

int ans, mx;

int main(){
    for(int i = 3 ; i <= SZ ; i++){
        int ii = i;
        while(ii%2==0) ii/=2;
        while(ii%5==0) ii/=5;
        if(mx < cycle_len(ii)){
            ans = ii;
            mx = cycle_len(ii);
        }
    }
    cout << ans;
}
