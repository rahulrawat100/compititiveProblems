class Solution {
public:
    void Add(vector<vector<int>>& heights,queue<pair<int, int>>& q, int i, int j, int prev, vector<vector<bool>>& trav)
    {
        int m = heights.size();
        int n = heights[0].size();

        if(i<0 || j<0 || i==m || j==n || trav[i][j] || heights[i][j]<prev)
           return;
        trav[i][j]=true;   
        q.push({i, j});
    }
    void possP(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& trav, vector<vector<int>>& pac)
    {
          while(!q.empty())
          {
              pair<int, int> p = q.front();
              q.pop();
              int i = p.first;
              int j = p.second;
              pac[i][j]+=1;
              Add(heights, q, i+1, j, heights[i][j], trav);
              Add(heights, q, i-1, j, heights[i][j], trav);
              Add(heights, q, i, j+1, heights[i][j], trav);
              Add(heights, q, i, j-1, heights[i][j], trav);
          }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> trav(m, vector<bool>(n));
        vector<vector<bool>> trav1(m, vector<bool>(n));
        vector<vector<int>> poss(m, vector<int>(n, 0));
        for(int i=0; i<n; i++)
        {
           q.push({0, i});
           trav[0][i]=true;
        }
        for(int i=1; i<m; i++)
        {
           q.push({i, 0});
           trav[i][0]=true;
        }
        possP(heights, q, trav, poss);
        while(!q.empty())
        {
            q.pop();
        }
        for(int i=0; i<n; i++)
        {
           q.push({m-1, i});
           trav1[m-1][i]=true;
        }
        for(int i=0; i<m-1; i++)
        {
           q.push({i, n-1});
           trav1[i][n-1]=true;
        }
        possP(heights, q, trav1, poss);
        vector<vector<int>> res;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(poss[i][j]==2)
                  res.push_back({i, j});
            }
        }
        return res;




    }
};