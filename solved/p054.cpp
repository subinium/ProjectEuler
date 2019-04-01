#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

int ans;

pii ck(string card){
  int idx = 0, suit = 0;
  char c = card[0];
  if(c>='2'&&c<='9') idx = c - '0';
  else if(c=='T') idx = 10;
  else if(c=='J') idx = 11;
  else if(c=='Q') idx = 12;
  else if(c=='K') idx = 13;
  else if(c=='A') idx = 14;
  c = card[1];
  if(c=='H') suit = 0;
  else if(c=='C') suit = 1;
  else if(c=='D') suit = 2;
  else if(c=='S') suit = 3;
  return make_pair(idx, suit);
}

pii score(vector<pii> v){
  int flush_ck = 1;
  for(int i = 0 ; i < 4 ; i++){
    if(v[i].s!=v[i+1].s) flush_ck = 0;
  }
  int strait_ck = 1, sth = 0;
  for(int i = 0 ; i < 4 ; i++){
    if(v[i].f+1!=v[i+1].f) strait_ck = 0;
  }
  sth = v[4].f;
  if(!strait_ck){
    int tck = 1;
    for(int i = 0 ; i < 4; i++) if(v[i].f != i+2) tck = 0;
    if(v[4].f!=14) tck = 0;
    strait_ck = tck;
    sth = 5;
  }

  int four_kind = 0, fkh = 0;
  for(int i = 0 ; i < 2 ; i++){
    set<int> stmp;
    for(int j = 0 ; j < 4 ; j++){
      stmp.insert(v[i+j].f);
    }
    if(stmp.size()==1) four_kind = 1;
    if(four_kind){
      fkh = v[i].f * 15 + v[(i==0?4:0)].f;
      break;
    }
  }
  int full_house = 0, fhh = 0;
  set<int> fh_st;
  for(int i = 0 ; i < 5 ; i++){
    fh_st.insert(v[i].f);
  }
  if(fh_st.size()==2) full_house = 1, fhh = v[2].f * 15 + v[(v[1]==v[2]?3:1)].f;
  int three_kind = 0, tkh = 0;
  for(int i = 0 ; i < 3 ; i++){
    set<int> stmp;
    for(int j = 0 ; j < 3 ; j++){
      stmp.insert(v[i+j].f);
    }
    if(stmp.size()==1) three_kind = 1;
    if(three_kind){
      tkh = v[i].f*225;
      if(i==0) tkh += v[4].f * 15 + v[3].f;
      if(i==1) tkh += v[4].f * 15 + v[0].f;
      if(i==2) tkh += v[2].f * 15 + v[1].f;
      break;
    }
  }
  int two_pair = 0, tph = 0;
  set<int> tp_st;
  for(int i = 0 ; i < 5 ; i++){
    tp_st.insert(v[i].f);
  }
  if(tp_st.size()==3){
    two_pair = 1;
    tph = v[3].f * 225 + v[1].f * 15;
    if(v[0].f!=v[1].f) tph += v[0].f;
    else if(v[3].f!=v[4].f) tph += v[4].f;
    else tph += v[2].f;
  }

  int one_pair = 0 , oph = 0, ophx = 0;
  for(int i = 4 ; i > 0 ; i--){
    if(v[i].f==v[i-1].f){
      one_pair = 1;
      oph = v[i].f;
      ophx = v[i].f;
      break;
    }
  }
  for(int i = 4 ; i >= 0 ; i--){
    if(ophx == v[i].f) continue;
    oph = oph * 15 + v[i].f;
  }

  int hs = 0;
  for(int i = 4 ; i >= 0 ; i--) hs = hs * 15 + v[i].f;
  
  if(flush_ck&&strait_ck&&v[0].f==10) return make_pair(10, 0);
  if(flush_ck&&strait_ck) return make_pair(9,sth);
  if(four_kind) return make_pair(8,fkh);
  if(full_house) return make_pair(7,fhh);
  if(flush_ck) return make_pair(6,hs);
  if(strait_ck) return make_pair(5,v[4].f);
  if(three_kind) return make_pair(4,tkh);
  if(two_pair) return make_pair(3,tph);
  if(one_pair) return make_pair(2,oph);
  return make_pair(1,hs);
}

void process(){
  vector<pii> p1, p2;
  for(int i = 0 ; i < 5 ; i++){
    string tmp; cin >> tmp;
    p1.push_back(ck(tmp));
  }
  for(int i = 0 ; i < 5 ; i++){
    string tmp; cin >> tmp;
    p2.push_back(ck(tmp));
  }
  sort(p1.begin(),p1.end());
  sort(p2.begin(),p2.end());
  ans += score(p1)>score(p2);
}
int main(){
  freopen("p054_poker.txt","r",stdin);
  for(int i = 1 ; i <= 1000 ; i++){
    process();
  }
  cout << ans;
}
