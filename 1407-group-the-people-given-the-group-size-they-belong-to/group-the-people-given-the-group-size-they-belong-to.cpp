class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> D;
        vector<vector<int>> ans;

        for(int i=0; i<groupSizes.size(); i++)
        {
            D[groupSizes[i]].push_back(i);
            if(D[groupSizes[i]].size()==groupSizes[i])
            {
                 ans.push_back(D[groupSizes[i]]);
                D[groupSizes[i]].clear();
            }
        }
        return ans;

    }
};