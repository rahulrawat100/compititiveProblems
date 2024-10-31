class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> D;
        int res=1;
        D[nums[0]]=1;
        for(int i=1; i<nums.size(); i++)
        {
             int x = sqrt(nums[i]);
             if(x*x==nums[i]&&D.find(x)!=D.end())
                D[nums[i]]=D[x]+1;
             else
                D[nums[i]]=1;   
             res=max(res, D[nums[i]]);   
        }
        return res==1?-1:res;

    }
};