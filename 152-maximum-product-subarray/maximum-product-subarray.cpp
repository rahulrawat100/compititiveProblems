class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minprod=nums[0];
        int maxprod=nums[0];

        int res=nums[0];
        for(int i=1; i<n; i++)
        {
            int temp = minprod;
            minprod=min(minprod*nums[i], maxprod*nums[i]);
            maxprod= max(maxprod*nums[i], nums[i]*temp);
            minprod=min(minprod, nums[i]);
            maxprod=max(maxprod, nums[i]);
            res=max(res, maxprod);
        }
        return res;
    }
};