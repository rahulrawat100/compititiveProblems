class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> D;
        int s=0;
        int res=0;
        D[0]=1;
        for(int i=0; i<n; i++)
        {
            s+=nums[i];
            if(D.find(s-goal)!=D.end())
              res+=D[s-goal];
            D[s]++;    
        }
        return res;
    }
};