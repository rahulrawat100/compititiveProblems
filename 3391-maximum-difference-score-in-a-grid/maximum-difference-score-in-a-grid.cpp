class Solution {
public:
    int calc(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& DP)
    {
        //cout<<i<<"  "<<j<<endl;
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j==n-1)
            return 0;
        if(DP[i][j]!=INT_MIN)
            return DP[i][j];
        else
        {
                int res=INT_MIN;
                if(i+1<m)
                    res=max(res, grid[i+1][j]-grid[i][j]+max(0, calc(grid, i+1, j,  DP)));
                 if(j+1<n)   
                    res=max(res, grid[i][j+1]-grid[i][j]+max(0, calc(grid, i, j+1, DP)));
                return DP[i][j]=res;
            
        }
    }
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res=INT_MIN;
            vector<vector<int>> DPd(m, vector<int>(n, INT_MIN));
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i<m-1||j<n-1)
                   res=max(res, calc(grid, i, j, DPd));
            }
        }
        return res;
    }
};
// [[6,5,1]
// ,[5,7,9]
// ,[6,7,4]
// ,[6,10,5]]