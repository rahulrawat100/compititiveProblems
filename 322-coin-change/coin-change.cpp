class Solution {
public:
    long long calc(vector<int>& coins, int amount, vector<int>& DP)
    {
        if(amount==0)
           return 0;
        else if(amount<coins[0])
           return INT_MAX;
        else if(DP[amount]!=-1)
            return DP[amount];   
        else
        {
            long long res=INT_MAX;

            for(int i=0; i<coins.size(); i++)
            {
                if(coins[i]>amount)break;
                res=min(res, 1+calc(coins, amount-coins[i], DP));
            }
            return DP[amount]=res;
        }      
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount+1, -1);
        sort(coins.begin(), coins.end());
        int res= calc(coins, amount, DP);
        return res==INT_MAX? -1:res;
    }
};