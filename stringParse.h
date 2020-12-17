#include <vector>
using namespace std;
#ifndef STRING_PARSE_H
#define STRING_PARSE_H

vector<string> stringParse(string s, string d){
  vector<string> ans;
  int curr = 0, next;
  do{
    next = s.find(d, curr);
    ans.push_back(s.substr(curr, next-curr));
    curr = next + d.size();
  } while(next != string::npos);
  return ans;
}

#endif