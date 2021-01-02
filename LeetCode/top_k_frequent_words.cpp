class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> m;

    for (auto w : words) {
      m[w]++;
    }

    vector<pair<string, int>> v(m.begin(), m.end());

    auto cmp = [](pair<string, int> a, pair<string, int> b) {
      if (a.second > b.second)
        return true;
      else if (a.second == b.second) {
        return a.first < b.first;
      }
      return false;
    };
    sort(v.begin(), v.end(), cmp);

    vector<string> ans;

    for (int i = 0; i < k; i++) {
      ans.push_back(v[i].first);
    }
    return ans;
  }
};