class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> DP(n, 1);
        vector<vector<int>> D(n);
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            for(int j=i-1;j>=0; j--)
            {
              if(nums[i]%nums[j]==0&&DP[i]<DP[j]+1)  
                {
                 DP[i]=DP[j]+1;
                 temp=D[j];
                }
            }
            temp.push_back(nums[i]);
            D[i]=temp;
            if(res.size()<temp.size())
              res=temp;
        }
        return res;
    }
};