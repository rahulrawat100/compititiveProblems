class Solution {
public:
    vector<vector<vector<unordered_map<int, int>>>> DP;
    int calc(vector<int>& nums, int k, int i, int prevInd, int mini)
    {
        int mod = pow(10, 9)+7;
        if(k==0)
           return mini;
        if(i==nums.size())
           return 0;
        if(DP[i][k][prevInd].find(mini)!=DP[i][k][prevInd].end())
           return DP[i][k][prevInd][mini];      
        else
        {
            return DP[i][k][prevInd][mini]=(calc(nums, k-1, i+1, i, min(mini, nums[i]-nums[prevInd]))+calc(nums, k, i+1, prevInd, mini))%mod;
        }   
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n =nums.size();
        sort(nums.begin(), nums.end());
        int res=0;
        vector<vector<unordered_map<int, int>>> D(k+1, vector<unordered_map<int, int>>(n));
        DP.resize(n, D);
        for(int i=0; i<n-k+1; i++)
        {
            int mod = pow(10, 9)+7;
            res+=calc(nums, k-1, i, i, INT_MAX);
            res=res%mod;
        }
        return res;
    }
};