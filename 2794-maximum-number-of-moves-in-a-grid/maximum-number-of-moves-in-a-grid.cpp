class Solution {
public:
    int dp[1001][1001];
    int Maxmove(vector<vector<int>>& grid, int i, int j, int prev)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i==m || j==n)
           return 0;
        if(grid[i][j]<=prev)
          return 0;
        if(dp[i][j]!=-1)
           return dp[i][j];  
        else
        {
            int res=0;
            res=max(res, Maxmove(grid, i-1, j+1, grid[i][j]));
            res=max(res, Maxmove(grid, i, j+1, grid[i][j]));
            res=max(res, Maxmove(grid, i+1, j+1, grid[i][j]));
            return dp[i][j]=res+1;
        }  
    }
    int maxMoves(vector<vector<int>>& grid) {
        int res=0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<grid.size(); i++)
        {
            res=max(res, Maxmove(grid, i, 0, INT_MIN)-1);
        }
        return res;
    }
};