class Solution {
public:
    void Add(int x, int y, priority_queue<pair<int, pair<int, int>>>& pq, vector<vector<bool>>& trav, vector<vector<int>>& grid, int curr)
    {
                int m = grid.size();
        int n = grid[0].size();
       if(x<0 || y< 0 || x == m || y==n || trav[x][y])
          return;
          trav[x][y]=true;
          int ob = grid[x][y]==1?curr-1:curr;
          pq.push({ob, {x, y}});
    }
    int calc(vector<vector<int>>& grid, priority_queue<pair<int, pair<int, int>>>& pq, vector<vector<bool>>& trav)
    {
        int m = grid.size();
        int n = grid[0].size();

        int curr=pq.top().first;

        while(pq.top().first==curr)
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x==m-1&& y==n-1)
               return -curr;
            Add(x+1, y, pq, trav, grid, curr);
            Add(x-1, y, pq, trav, grid, curr);
            Add(x, y+1, pq, trav, grid, curr);
            Add(x, y-1, pq, trav, grid, curr);
        }
        return calc(grid, pq, trav);
    }
    int minimumObstacles(vector<vector<int>>& grid) {
                int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<bool>> trav(m, vector<bool>(n));
        return calc(grid, pq, trav);
    }
};