class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        for(int i=1; i<n; i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
       for(int i=n-2; i>=0; i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        vector<int> res(n);

        for(int i=0; i<n; i++)
        {
            if(i==0)
              res[i]=right[0];
            else if(i==n-1)
              res[i]=left[n-1];
            else
              res[i]=left[i]*right[i];    
        }
        return res;
    }
};