class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();

        for(int i=0; i<n; i++)
        {
            nums[i]=nums[i]%2;
            if(i>0)
               nums[i]+=nums[i-1];
        }
        unordered_map<int, int> D;

        for(int i=0; i<n; i++)
        {
            D[nums[i]]++;
        }
        D[0]++;
        int res=0;
        int j=0;
        for(int i=0; i<n; i++)
        {
          res+=D[nums[i]-k];
        }
        return res;
    }
};