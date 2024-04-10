class Solution {
public:
    void heapify(vector<int>& nums, int i, int ignore)
    {
        int n = nums.size();
        int left = 2*i+1;
        int right = 2*i+2;

        int maxi = i;
        if(left<n-ignore)
        {
            if(nums[left]>nums[maxi])
               maxi=left;
        }
        if(right<n-ignore)
        {
            if(nums[right]>nums[maxi])
               maxi=right;
        }
        if(maxi!=i)
        {
            int t = nums[i];
            nums[i]=nums[maxi];
            nums[maxi]=t;
            heapify(nums, maxi, ignore);
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
            int t=nums[n-1-i];
            nums[n-1-i]=nums[0];
            nums[0]=t;
            heapify(nums, 0, i+1);
 
        }
        return nums;
    }
};