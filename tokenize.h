#include <bits/stdc++.h>
using namespace std;
#ifndef TOKENIZE_H
#define TOKENIZE_H

vector<string> tokenize(string s, char d)
{
  vector<string> ans;
  istringstream ss(s);
  string token;
  while(getline(ss, token, d)){
    ans.push_back(token);
  }

  return ans;
}

#endif