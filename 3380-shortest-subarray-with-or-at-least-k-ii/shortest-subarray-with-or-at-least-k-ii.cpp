class Solution {
public:

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> bit(32, 0);
        int res=INT_MAX;
        int i=0;
        int j=0;
        int curr=0;
        if(k==0)return 1;
        while(j<n)
        {
            while(j<n&&curr<k)
            {
                int x = nums[j];
                int ind=0;
                while(x>0)
                {
                    if((x%2)==1)
                        bit[ind]++;
                    x=x/2;
                    ind++;
                }
                curr=curr|nums[j];
                j++;
            }
            cout<<i<<"  "<<j<<"  "<<curr<<endl;
            if(curr>=k)
            res=min(res, j-i);
            
            while(i<j&&curr>=k)
            {
                int x = nums[i];
                int ind=0;
                while(x>0)
                {
                    if((x%2)==1)
                    {
                        bit[ind]--;
                        if(bit[ind]==0)
                        curr-=pow(2, ind);
                    }
                    x=x/2;
                    ind++;
                }
                cout<<curr<<endl;
                res=min(res, j-i);
                i++;
            }
        }
        return res ==INT_MAX?-1:res;
    }
};