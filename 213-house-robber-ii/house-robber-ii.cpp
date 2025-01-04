class Solution {
public:
    int calc(vector<int>& nums, int i, vector<int>& DP, int n)
    {
        if(i>=n)
           return 0;
        else if(DP[i]!=-1)
           return DP[i];   
        else
        {
            return DP[i]=max(calc(nums, i+1, DP, n), nums[i]+calc(nums, i+2, DP, n));
        }   
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int> DP1(n+1, -1);
        vector<int> DP2(n+1, -1);
        return max(nums[0]+calc(nums, 2,DP1, n-1), calc(nums, 1, DP2, n));      
    }
};