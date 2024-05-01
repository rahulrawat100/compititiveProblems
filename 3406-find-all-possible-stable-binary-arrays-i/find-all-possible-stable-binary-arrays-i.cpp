class Solution {
public:
   int mod=pow(10, 9)+7;
   int dp[201][201][2];
    int calc(int zero, int one, int set, int lim)
    {
        if(zero==0&&one==0)
          return 1;
        if(dp[zero][one][set]!=-1)
           return dp[zero][one][set];  
        else
        {
            int ans=0;

            if(set==1)
            {
                for(int i=1; i<=min(one, lim); i++)
                {
                    ans=(ans+calc(zero, one-i, 0, lim))%mod;
                }
            }
            else
              {
                for(int i=1; i<=min(zero, lim); i++)
                {
                    ans=(ans+calc(zero-i, one, 1, lim))%mod;
                }
            }
            return dp[zero][one][set]=ans;
        }  
    }
    int numberOfStableArrays(int zero, int one, int limit) {
                 memset(dp,-1, sizeof(dp));
        int A= calc(zero, one, 0, limit);
        int B= calc(zero, one, 1, limit);
        return (A+B)%mod;
    }
};