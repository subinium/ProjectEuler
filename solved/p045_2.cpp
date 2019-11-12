#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Tn(ll n){ return n*(n+1)/2;}
ll Pn(ll n){ return n*(3*n-1)/2;}
ll Hn(ll n){ return n*(2*n-1);}

int main(){
	ll tp = 286, pp = 166, hp = 144;
	while(!(Tn(tp)==Pn(pp)&&Pn(pp)==Hn(hp))){
		ll T = Tn(tp), P = Pn(pp), H = Hn(hp);
		if(T <= P && T <= H) tp++;
		else if(P <= T && P <= H) pp++;
		else hp++;
	}
	cout << Tn(tp) << ' ' << Pn(pp) << ' ' << Hn(hp) << endl;
	cout << tp << ' ' << pp << ' ' << hp << endl;
}
