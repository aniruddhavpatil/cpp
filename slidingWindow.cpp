#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> arr = {1, 2, 3, 1, 2, 3, -1, -2, -3};
  int k = 3;
  int wsum = 0, maxw = 0;
  for(int i = 0; i < k; i++){
    wsum+=arr[i];
  }
  maxw = wsum;
  for(int i = k; i < arr.size(); i++){
    wsum += arr[i] - arr[i - k];
    maxw = max(maxw, wsum);
    cout<<wsum<<endl;
  }
  cout<<"maxw "<<maxw<<endl;
  return 0;
}