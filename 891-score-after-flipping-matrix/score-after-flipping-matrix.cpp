class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res=0;
        for(int i=0; i<m; i++)
        {
             if(grid[i][0]==0)
             {
                  for(int j=0; j<n; j++)
                  {
                      grid[i][j]=abs(grid[i][j]-1);
                  }
             }
        }

        for(int j=0; j<n; j++)
        {
            int count=0;
                  for(int i=0; i<m; i++)
                  {
                      if(grid[i][j]==1)
                         count++;
                  }
                  if(count<=m/2)
                  {
                    for(int i=0; i<m; i++)
                   {
                      grid[i][j]=abs(grid[i][j]-1);
                   }
                  }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(grid[i][j]==1) 
                res+=pow(2, n-1-j);
            }
        }
        return res;
    }
};