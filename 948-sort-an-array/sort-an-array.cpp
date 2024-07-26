class Solution {
public:
    void heapify(vector<int>& nums, int i, int ignore)
    {
        int c1 = 2*i+1;
        int c2 = 2*i+2;
        int maxi =i;
        //cout<<c1<<"  "<<c2<<endl;
        if(c1<(nums.size()-ignore)&&nums[c1]>nums[maxi])
           maxi = c1;
        if(c2<(nums.size()-ignore)&&nums[c2]>nums[maxi])
           maxi = c2;
        if(maxi!=i)
        {   
        int t= nums[maxi];
        nums[maxi]=nums[i];
        nums[i] = t;
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
            int t = nums[0];
            nums[0]=nums[n-1-i];
            nums[n-1-i]=t;
            heapify(nums, 0, i+1);
        }
        return nums;
    }
};