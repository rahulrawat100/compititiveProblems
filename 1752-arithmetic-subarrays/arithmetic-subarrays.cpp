class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<int> sum;
        int n = nums.size();
        int t=0;
        for(int i=0; i<n; i++)
        {
          t+=nums[i];
          sum.push_back(t);

        }

        vector<bool> res(l.size());

        for(int i=0; i<l.size(); i++)
        {
            int sumt = sum[r[i]]-sum[l[i]]+nums[l[i]];
        
            int mint = nums[l[i]];
            unordered_map<int, int> D;
            for(int j = l[i]; j<=r[i]; j++)
            {
                mint = min(mint, nums[j]);
                D[nums[j]]=j;
            }
            int m = r[i]-l[i]+1;
            int p = 2*(sumt-mint*m);
            int c = m*m-m;
            if(p%c!=0)
                continue;
            p=p/c;
            
            int ele=mint;
            bool has=true;
           for(int j = l[i]; j<=r[i]; j++)
            {
                if(D.find(ele)==D.end())
                   {
                       has=false;
                       break;
                   }
                   ele+=p;

                  
            }
             if(has)
              res[i]=true;



        }
        return res;
    }
};