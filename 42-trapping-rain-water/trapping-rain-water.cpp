class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int f=0;
        int res=0;
        int curr=0;
        for(int i=1;i<n; i++)
        {
            if(height[i]>=height[f])
            {
                res+=curr;
                curr=0;
                f=i;
            }
            else
              curr+=height[f]-height[i];
        }
        f=n-1;
        curr=0;
        for(int i=n-2;i>=0; i--)
        {
            if(height[i]>height[f])
            {
                res+=curr;
                curr=0;
                f=i;
            }
            else
              curr+=height[f]-height[i];
        }
        return res;
    }
};