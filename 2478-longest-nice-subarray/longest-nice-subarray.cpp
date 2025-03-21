class Solution {
public:
    bool Nice(vector<int>& bits)
    {
        for(int i=0; i<100; i++)
        {
            if(bits[i]>1)
              return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> bits(100, 0);

        int i=0;
        int j=0;
        int res=1;
        int t=INT_MAX;
        while(j<n)
        {
            int x = nums[j];
               int k=0;
               while(x>0)
               {
                    bits[k]+=x%2;
                    x/=2;
                    k++;
               }
           if(Nice(bits))
           {
              j++;
           }
           else
           {            int x = nums[j];
               int k=0;
               while(x>0)
               {
                    bits[k]-=x%2;
                    x/=2;
                    k++;
               }
               x = nums[i];
                k=0;
               while(x>0)
               {
                    bits[k]-=x%2;
                    x/=2;
                    k++;
               }
               i++;
           }
            res=max(res, j-i);
        }
        return res;
    }
};