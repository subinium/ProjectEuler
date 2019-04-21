#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s = "123456789";

int main(){
    ll sum = 0;
    set<int> st;
    do{
        for(int i = 1 ; i <= 7 ; i++){
            for(int j = 1 ; i+j <= 8 ; j++){
                int a = stoi(s.substr(0, i));
                int b = stoi(s.substr(i,j));
                int c = stoi(s.substr(i+j, 9-i-j));
                if(a*b==c) st.insert(c);
            }
        }
    }while(next_permutation(s.begin(), s.end()));
    for(auto i : st){
        sum += (ll)i;
    }
    cout << sum << endl;
}
