class Solution {
public:
    int findMinMoves(vector<int>& nums) {
        int n = nums.size();
        int sum=0;

        for(int i=0; i<n; i++)
           sum+=nums[i];

        if(sum%n!=0)return -1;

        int tar=sum/n;
        int leftsum=0;
        int rightsum=sum;
        int res=0;
        for(int i=0; i<n; i++)
        {
            rightsum-=nums[i];
            int expr= (n-1-i)*tar;
            int expl=i*tar;
            res=max(res, max(0, expl-leftsum)+max(0, expr-rightsum));           
            leftsum+=nums[i];
        }   
        return res;
    }
};