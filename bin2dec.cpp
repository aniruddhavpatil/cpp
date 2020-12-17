#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int bin2dec(int n){
  int curr;
  int ans = 0;
  int count = 0;
  while(n){
    curr = n%10;
    n/=10;
    ans += (curr<<count);
    count++;
  }
  return ans;
}

int main(){
  cout<<bin2dec(1010);
  return 0;
}