class Solution {
public:
 int mod = pow(10, 9)+7;
    int calc(int i, int k, int n, vector<vector<int>>& DP)
    {
            if(k==0)
             return 1;
           if(i==n || k<0)
             return 0;
           if(DP[i][k]!=-1)
             return DP[i][k];  
           else
           {
               int res=0;
                for(int j=1;j<=n-i;j++)
                {
                    res+=calc(i+1, k-(j-1), n, DP);
                    res%=mod;
                    if(k-j+1<0)break;
                }
                return DP[i][k]=res;
           }  

    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> DP(n, vector<int>(k+1, -1));
        return calc(0, k, n, DP);
    }
};