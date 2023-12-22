class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> D;

        for(int i=0; i<paths.size(); i++)
        {
            D[paths[i][1]]++;
            D[paths[i][0]]--;
        }

        for(auto it: D)
        {
            if(it.second==1)return it.first;
        }
        return "";
    }
};