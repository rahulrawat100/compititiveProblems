class Solution {
public:
    void Add(vector<vector<int>>& ManDis, priority_queue<pair<int, pair<int, int>>>& pq, int x, int y, int res)
    {
        int n = ManDis.size();
        if(x<0 || y<0 || x==n || y==n || ManDis[x][y]==-1)
          return;
          res=min(res, ManDis[x][y]);
          ManDis[x][y]=-1;
        pq.push({res, {x, y}});
    }
    int calc(vector<vector<int>>& ManDis, priority_queue<pair<int, pair<int, int>>>& pq, int res)
    {
        int n = ManDis.size();
        int dis = pq.top().first;
        res=min(res, dis);

        while(!pq.empty()&&pq.top().first>=res)
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x==n-1&&y==n-1)
              return res;
            Add(ManDis, pq, x+1, y, res);
            Add(ManDis, pq, x-1, y, res);
            Add(ManDis, pq, x, y+1, res);
            Add(ManDis, pq, x, y-1, res);
        }
        return calc(ManDis, pq, res);
    }
    
    void Add1(vector<vector<int>>& grid, queue<pair<int, int>>& Q, int x, int y)
    {
        int n = grid.size();
        if(x<0 ||y<0 || x==n || y==n || grid[x][y] == -1)
          return ;
        grid[x][y]=-1;
        Q.push({x, y});
           
    }
    void calc2(vector<vector<int>>& grid, vector<vector<int>>& ManDis, queue<pair<int, int>>& Q, int dis)
    {
        int t = Q.size();

        while(t>0)
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            ManDis[x][y]=dis;
            Add1(grid, Q, x+1, y);
            Add1(grid, Q, x-1, y);
            Add1(grid, Q, x, y+1);
            Add1(grid, Q, x, y-1);
            t--;
        }
        if(Q.size()==0)return;
        return calc2(grid, ManDis, Q, dis+1);
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ManDis(n, vector<int>(n, INT_MAX));
queue<pair<int, int>> Q;
       vector<vector<int>> DP(n, vector<int>(n, INT_MIN));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(grid[i][j]==1)
               {
                  Q.push({i, j});
                  grid[i][j]=-1;
               } 
            }
        }
        calc2(grid, ManDis, Q, 0);
    //    for(int i=0; i<n; i++)
    //     {
    //         for(int j=0; j<n; j++)
    //         {
    //           cout<<ManDis[i][j]<<"  ";
    //         }
    //         cout<<endl;
    //     }
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({ManDis[0][0], {0, 0}});
        int res=INT_MAX;
        return calc(ManDis, pq, res);
    }
};