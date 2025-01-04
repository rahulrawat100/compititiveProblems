class Solution {
public:
    int calc(vector<int>& nums, int i, vector<int>& DP)
    {
        if(i>=nums.size())
           return 0;
        if(DP[i]!=-1)
           return DP[i];   
        else
           return DP[i]=max(calc(nums, i+1, DP), nums[i]+calc(nums, i+2, DP));   
    }
    int rob(vector<int>& nums) {
        vector<int> DP(nums.size(), -1);
        return calc(nums, 0, DP);
    }
};