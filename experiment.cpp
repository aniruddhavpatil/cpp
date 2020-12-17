#include<bits/stdc++.h>
using namespace std;


void printArr(const vector<int>& arr){
  for(auto item : arr){
    cout<<item<<' ';
  }
  cout<<'\n';
}
vector<int> constFunction(vector<int> arr){
  printArr(arr);
  arr[0] = 2;
  return arr;
}



int main(int argc, char** argv)
{
  vector<int> a = {0, 1, 2};
  constFunction(a);
  printArr(a);
  return 0;
}
