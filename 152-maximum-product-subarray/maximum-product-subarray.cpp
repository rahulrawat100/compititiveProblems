class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        double mint=nums[0];
        double maxt=nums[0];
        double res=nums[0];

        for(int i=1; i<n; i++)
        {
            if(nums[i]>0)
            {
                maxt=max((double)nums[i], maxt*nums[i]);
                mint=min((double)nums[i], mint*nums[i]);
            }
            else if(nums[i]<0)
            {
                double t=mint;
                mint = min((double)nums[i], maxt*nums[i]);
                maxt= max((double)nums[i], t*nums[i]);
            }
            else
            {
                maxt = 0;
                mint = 0;
            }
            res=max(res, maxt);
        }
        return res;
    }
};