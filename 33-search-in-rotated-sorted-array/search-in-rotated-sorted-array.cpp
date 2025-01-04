class Solution {
public:
    int FindStart(vector<int>& nums, int i, int j)
    {
        if(i==j)
            return i;
        else
        {
            int mid = i+(j-i)/2;

            if(nums[0]<=nums[mid])
                return FindStart(nums, mid+1, j);
            else
                return FindStart(nums, i, mid);    
        }    
    }

    int binser(vector<int>& nums, int i, int j, int target)
    {
        if(i>j)
           return -1;
        if(i==j)
            return nums[i]==target?i:-1;
        else
        {
            int mid = i+(j-i)/2;

            if(nums[mid]<target)
                return binser(nums, mid+1, j, target);
            else if(nums[mid]>target)
                return binser(nums, i, mid-1, target);
            else
                return mid;         
        }    
    }

    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int pivot = nums[0]<nums[n-1]?0:FindStart(nums, 0, n-1);

        if(target<=nums[n-1])
           return binser(nums, pivot, n-1, target);
        return binser(nums, 0, pivot-1, target);   
    }
};