class Solution {
public:
    int rev(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum= sum*10+n%10;
            n=n/10;
        }
        return sum;
    }
    int countNicePairs(vector<int>& nums) {
        int count=0;
        unordered_map<int, int> D;
        for(int i=0; i<nums.size(); i++)
            count=(count+D[nums[i]-rev(nums[i])]++)%1000000007;
        return count;
    }
};