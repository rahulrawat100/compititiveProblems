class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> Pos;

        int n = nums.size();
         vector<vector<int>> res;
         vector<int> D;
        for(int i=0; i<n; i++)
        {
            if(Pos.find(nums[i])==Pos.end())
               {
                    
                   if(res.size()==0)
                      res.push_back(D);
                    res[0].push_back(nums[i]);
                     Pos[nums[i]]=1;
               }
               else
               {
                   if(res.size()<=Pos[nums[i]])
                     res.push_back(D);
                    res[Pos[nums[i]]].push_back(nums[i]);
                    Pos[nums[i]]++; 
               }
        }
        return res;
    }
};