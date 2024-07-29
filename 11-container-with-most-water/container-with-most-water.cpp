class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i=0;
        int j=n-1;
        int res=min(height[i], height[j])*(j-i);
        while(i<j)
        {
           if(height[i]<height[j])
           {
               int k=i+1;
               while(k<n&&height[k]<height[i])
               {
                  k++;
               }
               i=k;
           }
           else
           {
               int k=j-1;
               while(k>=0&&height[k]<height[j])
               {
                  k--;
               }
               j=k;
           }
           res= max(res, min(height[i], height[j])*(j-i));

        }
        return res;
    }
};