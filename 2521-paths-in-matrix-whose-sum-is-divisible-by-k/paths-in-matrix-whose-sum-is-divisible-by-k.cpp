class Solution {
public:
    int calc(vector<vector<int>>& grid, int k, int i, int j, int s, vector<vector<vector<int>>>& DP)
    {
        int m =grid.size();
        int n =grid[0].size();
        int mod = pow(10, 9)+7;
        if(i<0 || j<0 || i ==m || j==n)
           return 0;   
        if(i==m-1 && j==n-1)
          {
             if((s+grid[i][j])%k==0)
               return 1;
             return 0;  
          }
          if(DP[i][j][s]!=-1)
             return DP[i][j][s];   
        return DP[i][j][s]=(calc(grid, k, i+1, j, (s+grid[i][j])%k, DP)+ calc(grid, k, i, j+1, (s+grid[i][j])%k, DP))%mod;;  
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<vector<int>>> DP(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return calc(grid, k, 0, 0, 0, DP);
    }
};