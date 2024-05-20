class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n =nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> D;
        int res=0;
        for(int i=0; i<n; i++)
        {
           if(i>0&&nums[i]==nums[i-1])
           {
             if(k==0)
                {
                    res+=D[nums[i]];
                    D[nums[i]]=0;
                }
            continue;
           } 
           res+=D[nums[i]-k];
           D[nums[i]]=1;
        }
        return res;
    }
};
// 0,1 2,2,3,3,3,4,4,9