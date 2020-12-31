#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  unordered_map<char, int> m = {
      {'c', 3},
      {'a', 6},
      {'d', 2},
      {'r', 5},
  };

  vector<pair<char, int>> v(m.begin(), m.end());

  auto cmp = [](pair<char, int> a, pair<char, int> b){
      return a.second < b.second;
  };

  sort(v.begin(), v.end(), cmp);

  for(auto p : v){
      cout<< p.first << " : " << p.second<<endl;
  }

  return 0;
}