#include <cstdio>
#include <vector>
using namespace std;

int arr[28124],ck[60000];
vector<int> on;

int main(){
    for(int i = 1; i < 28124 ; i++){
        for(int j = 1; j < i ; j++){
            if(i%j==0) arr[i]+=j;
        }
    }
    for(int i = 1 ; i <= 28124 ; i++){
        if(arr[i]>i) on.push_back(i);
    }
    for(int i = 0 ; i < on.size() ; i++){
        for(int j = i ; j < on.size() ; j++){
            ck[on[i]+on[j]] = 1;
        }
    }
    long long sum = 0;
    for(int i = 1 ; i <= 28124 ; i++) if(!ck[i]) sum+=i;
    printf("%lld",sum);
}

