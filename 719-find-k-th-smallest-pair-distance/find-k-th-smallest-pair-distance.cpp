class Solution {
public:
    int calc(vector<int>& nums, int diff)
    {
        int n = nums.size();
         int res=0;
        for(int i=1; i<n; i++)
        {
            int ind = lower_bound(nums.begin(), nums.end(), nums[i]-diff)-nums.begin();
            res+=i-ind;
        }
        return res;
    }

    int bin(vector<int>& nums, int k, int i, int j)
    {
         if(i==j)
            return i;
         else
         {
            int mid = i+(j-i)/2;

            if(calc(nums, mid)>=k)
            {
                if(calc(nums, mid-1)<k)
                   return mid;
                else
                   return bin(nums, k, i, mid-1);   
            }
           else
           {
              if(calc(nums, mid+1)>=k)
                 return mid+1;
              else
                 return bin(nums, k, mid+1, j);   
           } 
         }   
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return bin(nums, k, 0, nums[n-1]);
        return 0;

    }
};


/*
N ELEMENTS

brute force

travese all pair of diff
priority_queue for storing smallerst k diff
returing pr.top()
nnlogk
we can notice for every number all grater are traversed
we can traverse if needed




*/