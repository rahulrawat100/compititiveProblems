class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }

        sort(nums.begin(), nums.end());
        int tot = 0;
        for(int i=0; i<=k; i++)
        {
            tot+=freq[nums[0]+i];
        }

        int res= freq[nums[0]]+max(0, min(numOperations, tot - freq[nums[0]]));


        for(int i=nums[0]+1;i<=nums[n-1]; i++)
        {
            tot = tot-freq[i-k-1]+freq[i+k];
            int curr = freq[i]+max(0, min(numOperations, tot - freq[i]));
            res = max(res, curr);
        }
        return res;
    }
};