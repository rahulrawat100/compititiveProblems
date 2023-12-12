class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int A=nums[0];
        int B=nums[1];

        for(int i=2; i<nums.size(); i++)
        {
            if(nums[i]>A||nums[i]>B)
            {
                if(A>B)
                {
                    B=nums[i];
                }
                else
                {
                    A=nums[i];
                }
            }
        }
        return (A-1)*(B-1);
    }
};