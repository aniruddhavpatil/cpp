#include <bits/stdc++.h>
using namespace std;
#ifndef STRING_PARSE_H
#define STRING_PARSE_H

vector<string> stringParse(string s, string d)
{
  vector<string> ans;
  size_t curr = 0, next;
  string token;

  do
  {
    next = s.find(d, curr);
    token = s.substr(curr, next - curr);
    curr = next + d.length();
    ans.push_back(token);
  } while (next != string::npos);

  return ans;
}

#endif