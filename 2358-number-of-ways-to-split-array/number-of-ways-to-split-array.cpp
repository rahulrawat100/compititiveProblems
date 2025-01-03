class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        
        long long tsum=0;
        int res=0;
        for(int i=0; i<n-1; i++)
        {
            tsum+=nums[i];
            if(2*tsum>=sum)
                res++;
        }
        return res;
    }
};