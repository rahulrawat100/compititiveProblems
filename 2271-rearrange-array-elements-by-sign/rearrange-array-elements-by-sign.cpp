class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
         bool poss;
         if(nums[0]>0)poss=true;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
              pos.push_back(nums[i]);
            else
              neg.push_back(nums[i]);
        }
        int p=0;
        for(int i=0; i<n; i++)
        {
            if(poss)
            {
               nums[i]=pos[p];
               p++;
            }
            else
            {
               nums[i]=neg[i-p];
            } 
            poss=!poss;
        }
        return nums;
    }
};