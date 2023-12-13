class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i=0;
        int j=0;
        
        unordered_map<int, int> freq;
        
        int res=0;
        while(j<n)
        {
           // cout<<i<<"  "<<j<<endl;
            while(j<n)
            {
                freq[nums[j]]++;
                j++;
                if(freq[nums[j-1]]>k)break;
            }
                        if(freq[nums[j-1]]<=k)return max(res, j-i);
            res=max(res, j-i-1);
            
            if(j==n)break;
            int no=nums[j-1];
            
            while(i<j&&freq[no]>k)
            {
                freq[nums[i]]--;
                i++;
            }
            
        }
         return res;
    }
};