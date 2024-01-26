class Solution {
public:
    int calc(int m, int n, int maxMove, int i, int j,vector<vector<vector<int>>>& DP)
    {
        int mod = pow(10, 9)+7;
        if(i<0 || j<0 || i==m || j==n)
          return 1;
        else if(maxMove==0)
          return 0;
        else if(DP[i][j][maxMove]!=-1)
          return DP[i][j][maxMove];  
        else
        {
            int res=0;
            res+=calc(m, n, maxMove-1, i+1, j, DP);
            res%=mod;
            res+=calc(m, n, maxMove-1, i-1, j, DP);
            res%=mod;
            res+=calc(m, n, maxMove-1, i, j+1, DP);
            res%=mod;
            res+=calc(m, n, maxMove-1, i, j-1, DP);
            return DP[i][j][maxMove]=res%mod;
        }    
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> DP(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return calc(m, n, maxMove, startRow, startColumn, DP);      
    }
};