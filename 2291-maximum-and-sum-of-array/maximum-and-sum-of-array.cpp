class Solution {
public:
    int calc(vector<int>& nums, int numSlots, int i, int t, vector<vector<int>>& DP)
    {
        int n = nums.size();
        if(i==n)
          return 0;
        if(DP[i][t]!=-1)
          return DP[i][t];  
        else
        {
            int res= calc(nums, numSlots, i+1, t, DP);
            int x=1;
            for(int j=1; j<=2*numSlots;j++)
            {
                x*=2;
                int y=(nums[i]&((j+1)/2));
                if((t&x)>0 ||y==0)
                  continue;
                t+=x;  
                res=max(res, y+ calc(nums, numSlots, i+1, t, DP)); 
                t-=x;
            }
            return DP[i][t]=res;
        }

    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<vector<int>> DP(nums.size(), vector<int>(pow(2,2*numSlots+1), -1));
        return calc(nums, numSlots, 0, 0, DP);   
    }
};