class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
         int r=0;
         int res=0;
         sort(coins.begin(), coins.end());
        for(int i=0; i<coins.size(); i++)
        {
             while(r+1<coins[i])
             {
                 r=2*r+1;
                 res++;
             }

             if(r>=target)
                return res;
             r=r+coins[i];   

        }

        while(r<target)
        {
            r=2*r+1;
            res++;
        }
        return res;
    }
};