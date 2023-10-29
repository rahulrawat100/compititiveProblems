class Solution {
public:
    
    long long calc(vector<int>& nums, int i, int k, vector<long long>& DP)
    {
        if(i>=nums.size()-2)
            return 0;
        if(DP[i]!=-1)
            return DP[i];
        else
        {
            if(nums[i+2]>=k)
                return DP[i]=calc(nums, i+3, k, DP);
            else if(nums[i+1]>=k)
                return DP[i]=calc(nums, i+2, k, DP);
            else if(nums[i]>=k)
                return DP[i]=calc(nums, i+1, k, DP);
            else
            {
                long long A=LONG_MAX;
               if(k-nums[i]<k-nums[i+1]&&k-nums[i]<k-nums[i+2])
                  A=min(A, k-nums[i]+calc(nums, i+1, k, DP));
                if(k-nums[i+1]<k-nums[i+2])
                  A=min(A, k-nums[i+1]+calc(nums, i+2, k, DP));
                A=min(A, k-nums[i+2]+calc(nums, i+3, k, DP));
                return DP[i]=A;
            }
        }
    }
    long long minIncrementOperations(vector<int>& nums, int k) {

        vector<long long> DP(nums.size(), -1);
        return calc(nums, 0, k, DP);
    }
};