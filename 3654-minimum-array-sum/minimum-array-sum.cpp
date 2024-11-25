class Solution {
public:
    int calc(vector<int>& nums, int k, int op1, int op2, int i, vector<vector<vector<int>>>& DP)
    {
        int n = nums.size();
        if(i==n)
            return 0;
        else if(DP[i][op1][op2]!=-1)
              return DP[i][op1][op2];
        else
        {
            int res=INT_MAX;
            res=min(res, nums[i]+calc(nums, k, op1, op2, i+1, DP));
            int val=nums[i];
            if(op1>0)
            {
                val=(val+1)/2;
                res=min(res, val+calc(nums, k, op1-1, op2, i+1, DP));
            }
            val=nums[i];
            if(op2>0&&val>=k)
            {
                val-=k;
                res=min(res, val+calc(nums, k, op1, op2-1, i+1, DP));
            }
            val=nums[i];
            val=(val+1)/2;
            val-=k;
            if(op1>0&&op2>0&&val>=0)
            {
                res=min(res, val+calc(nums, k, op1-1, op2-1, i+1, DP));
            }
            val=nums[i];
            val-=k;
            if(op1>0&&op2>0&&val>=0)
            {
                val=(val+1)/2;
                res=min(res, val+calc(nums, k, op1-1, op2-1, i+1, DP));
            }
           // cout<<i<<"  "<<op1<<"   "<<op2<<"  "<<res<<endl;
            return DP[i][op1][op2]=res;
        }
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
         vector<vector<vector<int>>> DP(n, vector<vector<int>>(op1+1, vector<int>(op2+1, -1)));
        return calc(nums, k, op1, op2, 0, DP);
    }
};