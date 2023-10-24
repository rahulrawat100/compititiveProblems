class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> DP(n, 0);
        int ans=nums[0];
        multiset<int> D;
        DP[0]=nums[0];
        D.insert(nums[0]);
        auto it = D.end();
        for(int i=1; i<n; i++)
        {
            it = D.end();
            it--;
            DP[i]=nums[i];
            DP[i]=max(DP[i], *it+nums[i]);
            ans=max(ans, DP[i]);
            D.insert(DP[i]);
            if(D.size()>k)
            {
               it = D.find(DP[i-k]);
               D.erase(it);
            }

        }
        return ans;
    }
};