#include <bits/stdc++.h>
#include "BST.h"
#include "stringParse.h"
using namespace std;

// TODO
TreeNode* constructTree(string s){
  vector<string> v = stringParse(s, " ");
  for(auto t: v){
    cout<<t<<endl;
  }
  return nullptr;
}

int main(){
  
  constructTree("2 null 3");

  return 0;
}
