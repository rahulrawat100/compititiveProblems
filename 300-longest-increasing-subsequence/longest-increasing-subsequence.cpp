class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> D;
        D.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            if(nums[i]>D.back())
                D.push_back(nums[i]);
            else
            {
               int ind= lower_bound(D.begin(), D.end(), nums[i])-D.begin();
               D[ind]=nums[i];
            }  
        }
        return D.size();
    }
};