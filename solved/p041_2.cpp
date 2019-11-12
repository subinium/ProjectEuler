#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> p;
bool ck[3000];

void era(){
	for(int i = 2 ; i < 3000 ; i++){
		if(ck[i]) continue;
		p.push_back(i);
		for(int j = 2*i ; j < 3000 ; j += i) ck[j] = true;
	}
}

bool isPrime(int n){
	for(auto i : p){
		if(i*i>n) break;
		if(n%i==0) return false;
	}
	return true;
}

int process(int n){
	int ret = 0;
	vector<int> x(n);
	for(int i = 1 ; i <= n ; i++) x[i-1] = i;
	do{
		int num = 0;
		for(auto i : x) num = num*10 + i;
		if(isPrime(num)) ret = num;
	}while(next_permutation(x.begin(), x.end()));
	return ret;
}

int main(){
	era();
	int mx = 0;
	for(int i = 4 ; i <= 7 ; i++) mx = max(mx, process(i));
	cout << mx;
}
