class Solution {
public:
    int calc(unordered_map<int, int>& D, int i)
    {
        if(D.find(i)==D.end())
           return 0;
         int x= D[i]+calc(D, i+1);
         D.erase(i);
         return x;  
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> D;
        for(int i=0; i<n; i++)
        {
            D[nums[i]]=1;
        }
        int res=0;
        for(int i=0; i<n; i++)
        {
            int x = calc(D, nums[i]);
            D[nums[i]]=x;
           res=max(res, x);
        }
        return res;

    }
};