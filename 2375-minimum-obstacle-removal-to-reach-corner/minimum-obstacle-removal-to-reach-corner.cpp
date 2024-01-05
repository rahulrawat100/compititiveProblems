class Solution {
public:
    void Add(vector<vector<int>>& grid,int x, int y, queue<pair<int, int>>& q1, queue<pair<int, int>>& q2, vector<vector<bool>>& trav)
    {
                int m = grid.size();
        int n = grid[0].size();
            if(x<0 || y<0 || x>=m || y>=n || trav[x][y])
              return;
            trav[x][y]=true;  
            if(grid[x][y]==1)
              q2.push({x, y});
            else
              q1.push({x, y});    
    }
    int calc(vector<vector<int>>& grid, queue<pair<int, int>>& q1, queue<pair<int, int>>& q2, vector<vector<bool>>& trav)
    {
        int m = grid.size();
        int n = grid[0].size();
        while(q1.size()>0)
        {
            int x= q1.front().first;
            int y= q1.front().second;
             q1.pop();
            if(x==m-1&&y==n-1)
              return 0;
              Add(grid, x+1, y, q1, q2, trav);
              Add(grid, x-1, y, q1, q2, trav);
              Add(grid, x, y+1, q1, q2, trav);
              Add(grid, x, y-1, q1, q2, trav); 
        }
        queue<pair<int, int>> q3;
        return 1+calc(grid, q2, q3, trav);
    }
    int minimumObstacles(vector<vector<int>>& grid) {
         queue<pair<int, int>> q1;
          queue<pair<int, int>> q2;
          q1.push({0, 0});
                  int m = grid.size();
        int n = grid[0].size();
          vector<vector<bool>> trav(m, vector<bool>(n));
          return calc(grid, q1, q2, trav);
    }
};