class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> DP(n, 1);
        int ans=1;
        for(int i=1; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]>nums[j])
                  DP[i]=max(DP[i], DP[j]+1);
            }
            ans=max(ans, DP[i]);
        }
        return ans;
    }
};