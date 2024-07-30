class Solution {
public:
    void calc(vector<vector<char>>& grid, int i, int j, int n)
    {
        if(i<0 || j<0 || i== grid.size() || j== grid[0].size() || grid[i][j]!='1')
           return;
        else
        {
            grid[i][j]='2';
            calc(grid, i+1, j, n);
            calc(grid, i-1, j, n);
            calc(grid, i, j+1, n);
            calc(grid, i, j-1, n);
        }   
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=1;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size();j++)
            {
                 if(grid[i][j]=='1')
                   {
                      calc(grid, i, j, ++res);
                   }
            }
        }
        return res-1;
    }
};