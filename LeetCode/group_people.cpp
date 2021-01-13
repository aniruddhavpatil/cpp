// 1282 Group the People Given the Group Size They Belong To
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans, gz(groupSizes.size() + 1);
        for(int i = 0 ; i < groupSizes.size(); ++i){
            gz[groupSizes[i]].push_back(i);
            if(gz[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back({});
                swap(ans.back(), gz[groupSizes[i]]);
            }
        }
        return ans;
    }
};