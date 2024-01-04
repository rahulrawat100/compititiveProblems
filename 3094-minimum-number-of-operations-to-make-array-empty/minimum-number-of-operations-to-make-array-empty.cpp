class Solution {
public:
    int getans(int val)
    {
        if(val%3==0)
            return val/3;
       else 
       {
           return 1+getans(val-2);
       }
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> freq;
        
        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }
        
        int count=0;
        
        for(auto it: freq)
        {
            int val = it.second;
            if(val==1)return -1;
            count+=getans(val);
        }
        return count;
    }
};