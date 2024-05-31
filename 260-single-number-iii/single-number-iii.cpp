class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long x=0;

        for(int i=0;i<n; i++)
        {
            x= x^nums[i];
        }

        int a=0;
        int b=0;
        x = x&(-x);
        for(int i=0; i<n; i++)
        {
            if((x&nums[i])>0)
              a^=nums[i];
            else
              b^=nums[i];  
        }
        return {a,b};


    }
};