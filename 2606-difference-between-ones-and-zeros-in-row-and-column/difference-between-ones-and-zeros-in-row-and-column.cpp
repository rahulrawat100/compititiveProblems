class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n, 0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
               if(grid[i][j]==1)
                  row[i]++;
            }
        }
        vector<int> col(m, 0);
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
               if(grid[i][j]==1)
                  col[j]++;
            }
        }
         vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                res[i][j]=2*row[i]+2*col[j]-m-n;
            }
        }
        return res;
    }
};