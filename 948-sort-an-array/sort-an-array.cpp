class Solution {
public:
    void heapify(vector<int>& nums, int i, int leave)
    {
        int n = nums.size();
        if(i>=n-leave)
           return;
        int left = 2*i+1;
        int right= 2*i+2;
        int min_ind = i;
        if(left<n-leave&&nums[left]>nums[min_ind])
           min_ind=left;
        if(right<n-leave&&nums[right]>nums[min_ind])
           min_ind=right;

        if(min_ind!=i)
        {
            int t= nums[min_ind];
            nums[min_ind]=nums[i];
            nums[i]=t;
            heapify(nums, min_ind, leave);
        }      
    }


    vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();

      for(int i=n/2; i>=0; i--)
      {
          heapify(nums, i, 0);
      }    

      for(int i=0; i<n-1; i++)
      {
         int t= nums[n-1-i];
         nums[n-1-i]=nums[0];
         nums[0]=t;
         heapify(nums, 0, i+1);
      }
      return nums;
    }
};