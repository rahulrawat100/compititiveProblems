class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> D;
         for(int i=0; i<n; i++)
        {
             D[nums[i]]=i;
         }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
         if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1; j<n; j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int st = -(nums[i]+nums[j]);
                if(st+nums[n-1]<0)
                    break;
                if((D.find(st)!=D.end()) &&(D[st]>j))
                {
                 ans.push_back({nums[i], nums[j], st});   
                }
            }
        }
        return ans;
        
        
    }
};