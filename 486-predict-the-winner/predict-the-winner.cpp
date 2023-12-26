class Solution {
public:
    bool calc(vector<int>& nums, int i, int j, bool A, int diff)
    {
          if(i==j)
          {
             if(A) 
             return (diff+nums[i])>=0;
          else
             return (diff-nums[i])>=0;
          }
         else if(A)
            return calc(nums, i+1, j, !A, diff+nums[i]) || calc(nums, i, j-1, !A, diff+nums[j]); 
         else
            return calc(nums, i+1, j, !A, diff-nums[i]) && calc(nums, i, j-1, !A, diff-nums[j]);      
    }     
    bool predictTheWinner(vector<int>& nums) {
        return calc(nums, 0, nums.size()-1, true, 0);
    }
};