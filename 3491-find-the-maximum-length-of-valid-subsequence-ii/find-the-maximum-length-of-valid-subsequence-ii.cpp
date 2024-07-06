class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int, int> D;
        int res=0;
        for(int i=0; i<n; i++)
        {
            nums[i]=nums[i]%k;
            D[nums[i]]++;
            res=max(res, D[nums[i]]);
        }
         
        for(auto it: D)
        {
            int i = it.first;
            for(auto jt: D)
            {
                int j=jt.first;
                if(i<=j)continue;
                int curr=-1;
                int len=0;
                for(int m=0; m<n; m++)
                {
                    if(curr==-1)
                    {
                        if(nums[m]==i)
                          curr=i;
                        if(nums[m]==j)
                          curr=j;  
                          
                    }
                    if(nums[m]==curr)
                    {
                        len++;
                        if(curr==i)
                           curr=j;
                        else
                           curr=i;   
                    }
                }
                res=max(res, len);
            }
        } 
        return res;
    }
};