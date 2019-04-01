#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans, len;

const int ERROR_CHECK = 1e5;

double op(int i, double a, double b){
    if(i==0) return a+b;
    if(i==1) return a-b;
    if(i==2) return a*b;
    if(i==3 && b != 0) return a/b;
    return ERROR_CHECK;
}

int calc_detail(vector<double> v, vector<int> order, vector<int> oper){
    for(int i = 0 ; i < 3 ; i++){
        int ord = order[i];
        for(int j = 0 ; j < i ; j++){
            if(order[j]<order[i]) ord--;
        }
        v[ord] = op(oper[i],v[ord],v[ord+1]);
        if(v[ord]==ERROR_CHECK) return 0;
        for(int j = ord+1 ; j < 3 ; j++){
            v[j] = v[j+1];
        }
    }
    if((int)v[0] != v[0] || v[0] <= 0) return 0;
    return (int)v[0];
}

set<int> calc(vector<double> v){
    vector<int> order;
    for(int i = 0 ; i < 3 ; i++) order.push_back(i);
    set<int> s;
    do{
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                for(int k = 0 ; k < 4 ; k++){
                    vector<int> oper;
                    oper.push_back(i);
                    oper.push_back(j);
                    oper.push_back(k);
                    s.insert(calc_detail(v, order, oper));
                }
            }
        }
    }while(next_permutation(order.begin(),order.end()));
    return s;
}

void ck(int k){
    int val = k;
    vector<double> v;
    while(k){
        v.push_back((double)(k%10));
        k /= 10;
    }
    sort(v.begin(), v.end());
    set<int> s;
    do{
        set<int> tmp = calc(v);
        for(int i : tmp) s.insert(i);
    }while(next_permutation(v.begin(),v.end()));
    for(int i = 1 ; ; i++){
        if(s.count(i)==0){
            if(i>len){
                ans = val;
                len = i;
            }
            return ;
        }
    }
}

void dfs(int idx, int val){
    if(idx==11) return ;
    if(val>=1000){
        ck(val);
        return ;
    }
    dfs(idx+1, val*10+idx);
    dfs(idx+1, val);
}

int main(){
    dfs(1,0);
    cout << ans;

}
