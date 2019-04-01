#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int mx = 1e7;
int arr[mx];

int main(){
  for(int i = 2 ; i < mx ; i++){
    if(arr[i]) continue;
    for(int j = i ; j < mx ; j+= i){
      arr[j]++;
    }
  }
  for(int i = 1 ; ; i++){
    if(arr[i]>=4&&arr[i+1]>=4&&arr[i+2]>=4&&arr[i+3]>=4){
      cout << i << endl;
      return 0;
    }
  }
}

