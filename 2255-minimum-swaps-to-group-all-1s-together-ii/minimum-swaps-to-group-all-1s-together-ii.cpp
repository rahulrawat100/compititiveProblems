class Solution {
public:
    int minSwaps(vector<int>& nums) {
         int n = nums.size();
        int count=0;

        for(int i=0; i<n; i++)
        {
              count+=nums[i];
        }
        int i=0;
        int j=0;
        int curr=0;
        int res=INT_MAX;
        while(j<n+count)
        {
            while(j<n+count&&(j-i)<count)
            {
                 curr+=nums[j%n];
                 j++;
            }
            //cout<<curr<<endl;
            res=min(res, count-curr);
            curr-=nums[i%n];
            i++;
        }
        return res;
    }
};