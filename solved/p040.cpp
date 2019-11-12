#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	int ans = 1, idx = 0, flag = 1, iflag = 1;
	for(int i = 1 ; iflag <= 1000000 ; i++){
		if(i/flag == 10) flag *= 10;
		int fflag = flag;
		int n = i ;
		while(fflag){
			idx++;
			if(idx == iflag){
				ans *= n/fflag;
				cout << n / fflag << endl;
				iflag *= 10;
			}
			n %= fflag;
			fflag /= 10;
		}
	}
	cout << ans;
}
