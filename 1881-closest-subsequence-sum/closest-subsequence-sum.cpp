class Solution {
public:
    vector<int> left;
    vector<int> right;
    void calc(vector<int>& nums, int i, int sum, bool isleft)
    {
        if(i==nums.size())
        {
          if(isleft)  
           left.push_back(sum);
          else
           right.push_back(sum);
        }
        else
        {
            calc(nums, i+1, sum+nums[i], isleft);
            calc(nums, i+1, sum, isleft);
        } 
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> L,R;
        for(int i=0; i<n; i++)
        {
            if(i<n/2)
              L.push_back(nums[i]);
            else
             R.push_back(nums[i]);  
        }
        calc(L, 0,  0, true);
        calc(R, 0,  0, false);

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int res=INT_MAX;
        for(int i=0; i<left.size();i++)
        {
            int tar=goal-left[i];
            auto it=lower_bound(right.begin(), right.end(), tar);
            if(it!=right.end())
            {
                res=min(res, abs(tar-*it));
            }
            if(it!=right.begin())
            {
              it--;
              res=min(res, abs(tar-*it));
            }
        }
        return res;
    }
};