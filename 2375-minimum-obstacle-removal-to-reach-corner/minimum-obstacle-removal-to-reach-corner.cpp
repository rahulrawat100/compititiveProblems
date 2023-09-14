class Solution {
public:
    void Add(vector<vector<int>>& grid,queue<pair<int, int>>& q1, queue<pair<int, int>>& q2, int x, int y, vector<vector<bool>>& trav)
    {
        int m = trav.size();
        int n = trav[0].size();
        if(x<0 ||y<0 || x==m || y==n ||trav[x][y])
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
        if(q1.size()>0)
        {
            int s=q1.size();
            while(s>0)
            {
                int x = q1.front().first;
                int y = q1.front().second;
                s--;
                q1.pop();
                if(x==m-1&&y==n-1)
                  return 0;  
                Add(grid,q1, q2, x+1, y, trav);
                Add(grid,q1, q2, x-1, y, trav);
                Add(grid,q1, q2, x, y+1, trav);
                Add(grid,q1, q2, x, y-1, trav);             
            }
            return calc(grid, q1, q2, trav);
        }
        else
        {
            int s=q2.size();
            while(s>0)
            {
                int x = q2.front().first;
                int y = q2.front().second;
                s--;
                q2.pop();
                Add(grid, q1, q2, x+1, y, trav);
                Add(grid, q1, q2, x-1, y, trav);
                Add(grid, q1, q2, x, y+1, trav);
                Add(grid, q1, q2, x, y-1, trav);             
            }
            return 1+calc(grid, q1, q2, trav);
        }

    }

    int minimumObstacles(vector<vector<int>>& grid) {
                int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> trav(m , vector<bool>(n));
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        q1.push({0, 0});
        return calc(grid, q1,q2,trav);
    }
};