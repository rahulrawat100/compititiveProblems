class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        queue<int> pos;
        queue<int> neg;
         bool poss;
         if(nums[0]>0)poss=true;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
              pos.push(nums[i]);
            else
              neg.push(nums[i]);
        }

        for(int i=0; i<n; i++)
        {
            if(poss)
            {
               nums[i]=pos.front();
               pos.pop();
            }
            else
            {
               nums[i]=neg.front();
               neg.pop();  
            } 
            poss=!poss;
        }
        return nums;
    }
};