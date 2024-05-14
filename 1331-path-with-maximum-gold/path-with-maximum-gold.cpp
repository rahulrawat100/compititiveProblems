class Solution {
public:
    int calc(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i==m || j==n || grid[i][j]==0)
          return 0;
        else
        {
            int x = grid[i][j];
            grid[i][j]-=x;
            int res=0;
            res=max(res, calc(grid, i+1, j));
            res=max(res, calc(grid, i-1, j));
            res=max(res, calc(grid, i, j+1));
            res=max(res, calc(grid, i, j-1));
            grid[i][j]+=x;
            return x+res;
        }  
           
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
              res=max(res, calc(grid, i, j));
            }
        }
        return res;
    }
};