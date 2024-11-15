class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        // for(int i=0; i<n; i++)
        // {
        //     cout<<nums[i]<<"  ";
        // }
        // cout<<endl;
        long long res=0;
        for(int i=0; i<n; i++)
        {
            int l = lower-nums[i];
            int u= upper - nums[i];

            auto it = lower_bound(nums.begin()+i+1, nums.end(), l);
            auto jt = upper_bound(nums.begin()+i+1, nums.end(), u);
            res+=jt-it;


        }
        return res;
    }
};