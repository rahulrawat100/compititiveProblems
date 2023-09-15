class Solution {
public:
    int calc(vector<int>& coins, int amount, int i, vector<vector<int>>& DP)
    {
        if(amount==0)
           return 0;
        else if(i==coins.size() || amount<0)
           return INT_MAX/2;
        else if(DP[i][amount]!=-1)
           return DP[i][amount];   
        else
           {
               return DP[i][amount]=min(1+calc(coins, amount-coins[i], i, DP), calc(coins, amount, i+1, DP));
           }      
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> DP(n, vector<int>(amount+1, -1));
        int res= calc(coins, amount, 0, DP);
        return res>=INT_MAX/2?-1:res;
    }
};