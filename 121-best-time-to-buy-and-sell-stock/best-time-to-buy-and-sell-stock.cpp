class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mint(n);
        vector<int> maxt(n);
        mint[0]=prices[0];
        for(int i=1; i<n; i++)
        {
            mint[i]=min(mint[i-1], prices[i]);
        }
         maxt[n-1]=prices[n-1];
        for(int i=n-2; i>=0; i--)
        {
            maxt[i]=max(maxt[i+1], prices[i]);
        }

        int res=0;

        for(int i=0; i<n-1; i++)
        {
            res=max(res, maxt[i+1]-mint[i]);
        }
        return res;
    }
};