class Solution {
public:
   int count(int n, int c, vector<vector<int>>& DP)
   {
       int mod = pow(10, 9)+7;
       if(n==0)
          return 1;
        else if(DP[n][c]!=-1)
          return DP[n][c];
        {
            if(c==0)
               return DP[n][c]=count(n-1, 1, DP)%mod;
            else if(c==1)
               return DP[n][c]=(count(n-1, 0, DP)+count(n-1, 2, DP))%mod;
            else if(c==2)
               return DP[n][c]=((count(n-1, 0, DP)+count(n-1, 1, DP))%mod+(count(n-1, 3, DP)+count(n-1, 4, DP))%mod)%mod; 
            else if(c==3)
               return DP[n][c]=(count(n-1, 2, DP)+count(n-1, 4, DP))%mod;
            else 
               return DP[n][c]=(count(n-1, 0, DP))%mod;           
        }  
   }
    int countVowelPermutation(int n) {
        int res=0;
        int mod = pow(10, 9)+7;
        vector<vector<int>> DP(n, vector<int>(5, -1));
        for(int i=0; i<5; i++)
        {
            res+=count(n-1, i, DP);
            res=res%mod;
        }
        return res;
    }
};