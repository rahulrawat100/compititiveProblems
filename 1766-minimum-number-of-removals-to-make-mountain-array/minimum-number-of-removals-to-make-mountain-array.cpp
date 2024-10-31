class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        int res=n;

        vector<int> DP1(n, 1);


        for(int i=0; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
               if(nums[j]<nums[i]) 
                  DP1[i]=max(DP1[i], 1+DP1[j]);
            }
           // cout<<i<<"  "<<DP1[i]<<endl;
        }

               
        vector<int> DP2(n, 1);
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
               if(nums[j]<nums[i]) 
                  DP2[i]=max(DP2[i], 1+DP2[j]);
            }
          //  cout<<i<<" -- "<<DP2[i]<<endl;
        }

        for(int i=1; i<n-1; i++)
        {
            if(DP1[i]>1&&DP2[i]>1)
            {
                int x=n-(DP1[i]+DP2[i]-1);
              //  cout<<i<<"  "<<x<<endl;
               res=min(res, x);
            }
          //  cout<<res<<endl;
        }
        return res;


    }
};