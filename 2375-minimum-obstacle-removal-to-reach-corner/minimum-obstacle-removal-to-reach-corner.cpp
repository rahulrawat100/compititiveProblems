class Solution {
public:
    void Add( vector<vector<int>>& grid, int i, int j, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>& pq, int x)
    {
        int m = grid.size();
       int n = grid[0].size();
        if(i<0 || j<0 || i==m || j==n || grid[i][j]==-1)
           return ;
        if(grid[i][j]==1)
           pq.push({x+1, {i, j}});
        else
          pq.push({x, {i, j}});
          grid[i][j]=-1;      
    }
    int calc(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>& pq, vector<vector<int>>& grid)
    {
        int x = pq.top().first;
       int m = grid.size();
       int n = grid[0].size();
        while(pq.top().first==x)
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(i==m-1&&j==n-1)
               return 0;
            Add(grid, i+1, j, pq,  x);
            Add(grid, i-1, j, pq,  x);
            Add(grid, i, j+1, pq,  x);
            Add(grid, i, j-1, pq,  x);   

        }
        return 1+calc(pq, grid);
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq ;
        pq.push({0, {0, 0}});
        return calc(pq, grid);
    }
};