class Solution {
public:
    int calc(vector<int>& nums, int target, vector<int>& DP)
    {
      //  cout<<target<<endl;
         if(target==0)
            return 1;
         if(target<0)
           return 0;
         if(DP[target]!=-1)
           return DP[target];     
         else
         {
             int sum=0;
             for(int i=0; i<nums.size(); i++)
             {
                 sum+=calc(nums, target-nums[i], DP);
             }
             return DP[target]=sum;
         } 

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> DP(target+1, -1);
          return calc(nums, target, DP);
    }
};