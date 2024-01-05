class Solution {
public:
    void checkPac(vector<vector<int>>& heights, int i, int j,int prev, vector<vector<int>>& DP)
    {
        cout<<i<<"  "<<j<<endl;
        int m = heights.size();
        int n = heights[0].size();
        if(i<0 || j<0 || i>=m || j>=n || heights[i][j]<prev|| DP[i][j]==1)
           return ; 
        else
          {
              DP[i][j]=1;
              checkPac(heights, i+1, j, heights[i][j], DP);
              checkPac(heights, i-1, j, heights[i][j], DP);
              checkPac(heights, i, j+1, heights[i][j], DP);
              checkPac(heights, i, j-1, heights[i][j], DP);      
          }  
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
                        vector<vector<int>> DP1(m, vector<int>(n, -1));
                 vector<vector<int>> DP2(m, vector<int>(n, -1));
                 for(int i=0; i<m; i++)
                 {
                     for(int j=0;j<n; j++)
                     {
                         if(i==0||j==0)
                           DP1[i][j]=1;
                         if(i==m-1||j==n-1)
                           DP2[i][j]=1;  
                     }
                 }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(DP1[i][j]==1)
                {
                cout<<"Pac"<<"  "<<i<<"  "<<j<<endl;
                 checkPac(heights, i+1, j, heights[i][j], DP1);
                 checkPac(heights, i-1, j, heights[i][j], DP1);
                 checkPac(heights, i, j+1, heights[i][j], DP1);
                 checkPac(heights, i, j-1, heights[i][j], DP1);
                }
                if(DP2[i][j]==1)
                {
                 cout<<"Atl"<<"  "<<i<<"  "<<j<<endl;
                 checkPac(heights, i+1, j, heights[i][j], DP2);
                 checkPac(heights, i-1, j, heights[i][j], DP2);
                 checkPac(heights, i, j+1, heights[i][j], DP2);
                 checkPac(heights, i, j-1, heights[i][j], DP2);
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                 if(DP1[i][j]==1&&DP2[i][j]==1)
                   res.push_back({i,j});
            }
        }
        return res;
    }
};