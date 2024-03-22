
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
        return 1+calc(grid, q2, q1, trav);
    }
    void Add(vector<vector<int>>& grid, priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>>& pq, vector<vector<bool>>& trav, int x, int y, int z)
    {
        if(x<0 || y<0 || x == grid.size() || y == grid[0].size() || trav[x][y])
           return;
           trav[x][y]=true;
         if(grid[x][y]==1)
             pq.push({z+1, {x, y}});
         else
            pq.push({z, {x, y}});    
    }
    int calc(vector<vector<int>>& grid, priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>>& pq, vector<vector<bool>>& trav)
    {
        int b = pq.top().first;
        //cout<<b<<endl;
        while(pq.top().first==b)
        {
            int x = pq.top().second.first;
            int y= pq.top().second.second;
            //cout<<x<<"  "<<y<<endl;
            int z=  pq.top().first;
            pq.pop();
            if(x == grid.size()-1&&y==grid[0].size()-1)
              return z;
            Add(grid, pq, trav, x+1, y, z);
            Add(grid, pq, trav, x-1, y, z);
            Add(grid, pq, trav, x, y+1, z);
            Add(grid, pq, trav, x, y-1, z);
        }
        return calc(grid, pq, trav);
    }

    int minimumObstacles(vector<vector<int>>& grid) {
         queue<pair<int, int>> q1;
          queue<pair<int, int>> q2;
          q1.push({0, 0});
                  int m = grid.size();
        int n = grid[0].size();
          vector<vector<bool>> trav(m, vector<bool>(n));
          priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
          pq.push({0, {0,0}});
                  return calc(grid, pq, trav);
          return calc(grid, q1, q2, trav);
    }
};