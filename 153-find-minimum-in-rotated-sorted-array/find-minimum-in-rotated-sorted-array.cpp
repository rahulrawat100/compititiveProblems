class Solution {
public:
    int binser(vector<int>& nums, int i, int j)
    {
        if(i==j)
           return nums[i];
        else
        {
            int mid = i+(j-i)/2;

            if(nums[mid]>=nums[0])
               return binser(nums, mid+1, j);
            else
               return binser(nums, i, mid);   
        }   
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<nums[n-1])
           return nums[0];
        return binser(nums, 0, n-1);
    }
};