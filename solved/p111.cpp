#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int SZ = 1e5, L = 10;

vector<ll> p;
bool ck[SZ];

void era(){
  for(ll i = 2 ; i < SZ ; i++){
    if(ck[i]) continue;
    p.push_back(i);
    for(ll j = i*i ; j < SZ ; j+=i){
      ck[j] = true;
    }
  }
}

ll stoLL(string s){
  ll ret = 0;
  for(auto i : s) ret = ret * 10 + i-'0';
  return ret;
}

string ltos(ll n){
  string ret;
  while(n){
    ret += (char)(n%10+'0');
    n /= 10;
  }
  return ret;
}

bool prime_ck(string s){
  ll n = stoLL(s);
  for(auto i: p){
    if(i*i>= n) break;
    if(n%i==0) return false;
  }
  return true;
}

bool Mck(int len, int d, int dlen){
  string s;
  for(int i = 0 ; i < dlen ; i++) s+= (char)('0'+d);
  ll scp = 1;
  for(int i = 0 ; i < len-dlen ; i++) scp *= 10;
  for(ll i = scp/10 ; i < scp ; i++){
    string ns = s + ltos(i);
    sort(ns.begin(),ns.end());
    do{
      if(ns[0]=='0') continue;
      if(prime_ck(ns)) return true;
    }while(next_permutation(ns.begin(),ns.end()));
  }
  return false;
}

// find the value of M(len, d)
int M(int len, int d){
  string s;
  for(int i = len-1 ; i >= 0 ; i--){
    if(Mck(len, d, i)) return i;
  }
  return -1;
}

// find M(len, d) and find sum of all prime
ll S(int len, int d){
  int Mval = M(len, d);
  string s;
  ll scp = 1, ret = 0;
  for(int i = 0 ; i < Mval ; i++) s+= (char)('0'+d);
  for(int i = 0 ; i < len-Mval ; i++) scp *= 10;
  set<string> st;
  for(int i = scp/10 ; i < scp ; i++){
    string ns = s + ltos(i);
    sort(ns.begin(),ns.end());
    if(st.count(ns)) continue;
    st.insert(ns);
    do{
      if(ns[0]=='0') continue;
      if(prime_ck(ns)) ret += stoLL(ns);
    }while(next_permutation(ns.begin(),ns.end()));
  }
  return ret;
}

int main(){
  era();
  ll ans = 0;
  for(int i = 0 ; i < 10 ; i++) ans += S(10,i);
  cout << ans;
}
