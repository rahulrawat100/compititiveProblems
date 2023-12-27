class Solution {
public:
    int count(vector<int>& nums, int i, int low, int high, int ct)
    {
        if(ct>=high)return 0;
        if(i==nums.size())
          {
              if(ct>low && ct<high)
                 return 1;
               return 0;
          }
        else
        {
            return count(nums, i+1, max(low, nums[i]), high, ct+1)+count(nums, i+1, low, min(high, nums[i]), ct);
        }  
    }
    int countWays(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count=0;
         if(nums[0]>0)
           count++;
        for(int i=0; i<n-1; i++)
        {
            if(i+1>nums[i] &&i+1<nums[i+1])
               count++;
        }
        if(nums[n-1]<n)count++;
        return count;
       // return count(nums, 0, INT_MIN, INT_MAX, 0);
    }
};