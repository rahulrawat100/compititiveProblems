class Solution {
public:
    int mod = pow(10, 9)+7;
    unordered_map<int, long long> powDP;
    long long power(int powi)
    {
        if(powDP.find(powi)!=powDP.end())
           return powDP[powi];
        if(powi<=60)
            return powDP[powi]=(long long)pow(2, powi)%mod;
        return powDP[powi]=(long long)(power(powi-1)+power(powi-1))%mod;
    }
    long long calc(vector<int>& nums, int i, int k, int count, vector<vector<unordered_map<int, long long>>>& DP)
    {
        if(i==nums.size())
        {
            if(k==0)
                return power(nums.size()-count);
            else
                return 0;
        }
        if(k<0)
            return 0;
        if(DP[i][count].find(k)!=DP[i][count].end())
            return DP[i][count][k];
        else
            return DP[i][count][k]=(calc(nums, i+1, k-nums[i], count+1, DP)+calc(nums, i+1, k, count, DP))%mod;
    }
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<unordered_map<int, long long>>> DP(n, vector<unordered_map<int, long long>>(n));
        return calc(nums, 0, k, 0, DP);
    }
};

