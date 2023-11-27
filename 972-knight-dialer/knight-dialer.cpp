class Solution {
public:
    int calc(int n, int c, vector<vector<int>>& DP)
    {
        int mod = pow(10, 9)+7;
          if(n==0)
            return 1;
          if(DP[n][c]!=-1)
            return DP[n][c];  
          else
            {
                int s;
                if(c==1)
                   s= calc(n-1, 8, DP)+calc(n-1, 6, DP);
                else if(c==2)
                   s= calc(n-1, 7, DP)+calc(n-1, 9, DP);
                else if(c==3)
                   s= calc(n-1, 4, DP)+calc(n-1, 8, DP); 
                else if(c==4)
                   s= (calc(n-1, 3, DP)+calc(n-1, 9, DP))%mod+calc(n-1, 0, DP);
                else if(c==5)
                   s= 0;
                else if(c==6)
                   s= (calc(n-1, 1, DP)+calc(n-1, 7, DP))%mod+calc(n-1,0, DP);
                else if(c==7)
                   s= calc(n-1, 6, DP)+calc(n-1, 2, DP);
                else if(c==8)
                   s= calc(n-1, 1, DP)+calc(n-1, 3, DP);
                else if(c==9)
                   s= calc(n-1, 4, DP)+calc(n-1, 2, DP);
                else
                   s= calc(n-1, 4, DP)+calc(n-1, 6, DP);
                   return DP[n][c]=s%mod;                 
            }  
    }
    int knightDialer(int n) {
        int s=0;
        int mod = pow(10, 9)+7;
        vector<vector<int>> DP(n, vector<int>(10, -1));
        for(int i=0; i<=9; i++)
        {
            s+=calc(n-1, i, DP);
            s=s%mod;
        }
        return s;
    }
};