class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos(n+1, 0);

        for(int j=n-1; j>=0; j--)
        {
            pos[j]=nums[j]+pos[j+1];
        }
        vector<int> res;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            res.push_back(nums[i]*(i+1)-sum+pos[i+1]-(n-i-1)*nums[i]);

        }
        return res;
    }
};