class Solution {
public:
    void sort(vector<int>& nums, int i, int j)
    {
        if(i==j)
           return;
        else
        {
            int mid = i+(j-i)/2;
            sort(nums, i, mid);
            sort(nums, mid+1, j);
            merge(nums, i, j);
        }   
    }

    void merge(vector<int>& nums, int i, int j)
    {

        vector<int> res;
        int mid = i +(j-i)/2;
        int m = mid+1;
        int i1=i; 
        int j1=mid+1;
        int n =j+1;


        while(i1<m || j1<n)
        {
            if(i1<m&&j1<n)
            {
                if(nums[i1]<nums[j1])
                {
                    res.push_back(nums[i1]);
                    i1++;
                }
                else
                {
                    res.push_back(nums[j1]);
                    j1++;
                }
            }
            else if(i1<m)
            {
                   res.push_back(nums[i1]);
                    i1++; 
            }
            else
            {
                    res.push_back(nums[j1]);
                    j1++;
            }
        }

        for(int k=0; k<res.size(); k++)
        {
            nums[i+k]=res[k];
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};