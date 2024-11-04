class Solution {
public:
    bool IsPoss(vector<int>& weights, int days, int wt)
    {
        int n = weights.size();
        int time=0;
        int i=0;
        while(i<n)
        {
            int curr=0;
            while(i<n)
            {
               curr+=weights[i];
               if(curr>wt)
                  break;
               i++;   
            }

            if(i<n&&weights[i]>wt)return false;
            time++;
        }
        return time<=days;
    }
    int GetWt(vector<int>& weights,int i, int j, int days)
    {
        if(i>j)
          return -1;
        if(i==j)
           return i;
        else
        {
            int mid = i+(j-i)/2;

            if(IsPoss(weights, days, mid))
                return GetWt(weights, i, mid, days);
            else
                return GetWt(weights, mid+1, j, days);    
        }   
    }
    int shipWithinDays(vector<int>& weights, int days) {
        return GetWt(weights, 1, INT_MAX, days);
    }
};