class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int> D;
        D[0]++;
        for(int i=0; i<n; i++)
        {
            nums[i]=nums[i]%2;
            if(i>0)
               nums[i]+=nums[i-1];
                 D[nums[i]]++;
        }
        int res=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]-k>=0)
           res+=D[nums[i]-k];
        }
        return res;
    }
};