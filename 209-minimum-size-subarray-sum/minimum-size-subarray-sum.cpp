class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0; 
        int j=0;
        int curr=0;
        int res=n+1;
        while(j<n)
        {
            while(j<n&&curr<target)
            {
                curr+=nums[j];
                j++;
            }
            if(curr>=target)
                res=min(res, j-i);
            while(i<j&&curr>=target)
            {
                res=min(res, j-i);
                curr-=nums[i];
                i++;
            }    
        }
        return res == n+1?0:res;
    }
};