class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i=1; i<n; i++)
        {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);

            if(it==lis.end())
               lis.push_back(nums[i]);
            else
            {
                int ind = it-lis.begin();
                lis[ind]=nums[i];
            }
                  
        }
        return lis.size();
    }
};