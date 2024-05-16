class Solution {
public:
    long long cost(vector<int>& nums, long long cost1, long long cost2, long long target, long long sum)
    {
        int n = nums.size();
        long long diffs = n*target-sum;
        if(2*cost1<=cost2)
           return diffs*cost1;
        int maxdiff = target-nums[0];
                      long long k= diffs-maxdiff;
        if(maxdiff>k)
           {
              return (k*cost2+(maxdiff-k)*cost1);
           }
        if(diffs%2==0)
           return (cost2*(diffs/2));
        else
           return (cost2*(diffs/2)+cost1);      
    }
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        int mod = pow(10, 9)+7;
        sort(nums.begin(), nums.end());
        long long sum=0;
        if(nums[0]==nums[n-1])return 0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        long long res=LONG_MAX;
        for(int i=nums[n-1]; i<=4*nums[n-1]; i++)
        {
            res=min(res, cost(nums, cost1, cost2, i, sum));
        }
       // cout<<res<<endl;
        return res%mod;
    }
};