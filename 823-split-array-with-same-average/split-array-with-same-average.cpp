class Solution {
public:

    void calc(vector<int>& nums, int i, int count, int sum, vector<vector<int>>& DP)
    {
        if(i==nums.size())
           DP[count].push_back(sum);
        else
        {
            calc(nums, i+1, count, sum, DP);
            calc(nums, i+1, count+1, sum+nums[i], DP);
        }   
    }


    bool splitArraySameAverage(vector<int>& nums) {
        int n =nums.size();

        double sum=0;
        vector<int> left, right;
        for(int i=0; i<n; i++)
        {
            if(i<n/2)
               left.push_back(nums[i]);
            else
               right.push_back(nums[i]);   
            sum+=nums[i];
        }

        vector<vector<int>> DPleft(left.size()+1);
        vector<vector<int>> DPright(right.size()+1);
        calc(left, 0, 0, 0, DPleft);
        calc(right, 0, 0, 0, DPright);

        for(int i=0; i<DPleft.size();i++)
        {
            sort(DPleft[i].begin(), DPleft[i].end());
        }
        for(int i=0; i<DPright.size();i++)
        {
            sort(DPright[i].begin(), DPright[i].end());
        }        
        double avg = sum/n;
        
        for(int i=1; i<=n/2;i++)
        {
            double target = avg*i;
            int tar=target;
            if(target-tar<0.000001)
            { 
                //cout<<i<<"  "<<tar<<endl;
                if(i<DPleft.size())
                {
                    auto it = lower_bound(DPleft[i].begin(),DPleft[i].end(),tar);
                    if(it!=DPleft[i].end()&&*it==tar)
                             return true;
                }
                if(i<DPright.size())
                {
                    auto it = lower_bound(DPright[i].begin(),DPright[i].end(),tar);
                    if(it!=DPright[i].end()&&*it==tar)
                             return true;
                }
               for(int j=1; j<i;j++)
               {
                   for(int k=0; k<DPleft[j].size();k++)
                   {
                       int rtar = tar-DPleft[j][k];
                       if(rtar>=0)
                       {
                          auto it = lower_bound(DPright[i-j].begin(),DPright[i-j].end(),rtar);
                          if(it!=DPright[i-j].end()&&*it==rtar)
                             return true;
                       }
                       else
                       break;
                   }
               }
            }
        }
        return false;

    }
};