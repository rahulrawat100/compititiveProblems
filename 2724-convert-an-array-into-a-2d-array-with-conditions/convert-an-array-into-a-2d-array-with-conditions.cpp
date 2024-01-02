class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> Pos;

        int n = nums.size();
         vector<vector<int>> res;
        for(int i=0; i<n; i++)
        {
            if(Pos.find(nums[i])==Pos.end())
               {
                    vector<int> D;
                    D.push_back(nums[i]);
                   if(res.size()>0)
                     res[0].push_back(nums[i]);
                    else
                      res.push_back(D);
                     Pos[nums[i]]=1;
               }
               else
               {
                   vector<int> D;
                   if(res.size()<=Pos[nums[i]])
                     res.push_back(D);
                    res[Pos[nums[i]]].push_back(nums[i]);
                    Pos[nums[i]]++; 
               }
        }
        return res;
    }
};