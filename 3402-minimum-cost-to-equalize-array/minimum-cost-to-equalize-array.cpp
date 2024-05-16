class Solution {
public:
    long long cost(vector<int>& nums, long long cost1, long long cost2, long long target, long long sum, int mini)
    {
        int n = nums.size();
        long long diffs = n*target-sum;
        if(2*cost1<=cost2)
           return diffs*cost1;
        int maxdiff = target-mini;
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
        //sort(nums.begin(), nums.end());
        int mini=nums[0];
        int maxi=nums[0];
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            mini=min(mini, nums[i]);
            maxi=max(maxi, nums[i]);
        }
                if(mini==maxi)return 0;
        long long res=LONG_MAX;
        for(int i=maxi; i<=2*maxi; i++)
        {
            res=min(res, cost(nums, cost1, cost2, i, sum, mini));
        }
       // cout<<res<<endl;
        return res%mod;
    }
};