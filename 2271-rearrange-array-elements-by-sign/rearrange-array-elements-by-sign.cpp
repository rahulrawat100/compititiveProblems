class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        int p, n;
          p=0;
          n=1;
        for(int i=0; i<len; i++)
        {
            if(nums[i]>0)
            {
              res[p]=nums[i];
              p+=2;
            }
            else
            {
                res[n]=nums[i];
                n+=2;
            }
        }
        return res;
    }
};