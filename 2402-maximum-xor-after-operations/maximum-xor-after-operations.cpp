class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();
        int  res=0;
        for(int i=0; i<n; i++)
        {
            res=res|nums[i];
        }
        return res;
    }
};