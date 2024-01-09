class Solution {
public:
     void swap(vector<int>& nums,int i, int j)
     {
         int t=nums[i];
         nums[i]=nums[j];
         nums[j]=t;

     }
    void Heapify(vector<int>& nums, int i, int n)
    {
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        if(l<n&&nums[l]>nums[largest])
           largest=l;
        if(r<n&&nums[r]>nums[largest])
           largest=r;
        if(largest!=i)
        {
            swap(nums, i, largest);
            Heapify(nums, largest, n);
        }     

    }

    void heapsort(vector<int>& nums)
    {
        int n = nums.size();

        for(int i=n/2; i>=0; i--)
        {
            Heapify(nums, i, n);
        }

        for(int i=0; i<n; i++)
        {
            swap(nums, 0, n-1-i);
            Heapify(nums, 0, n-1-i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
           heapsort(nums);
           return nums;
    }
};
//      5
//    2   3  
//   1 