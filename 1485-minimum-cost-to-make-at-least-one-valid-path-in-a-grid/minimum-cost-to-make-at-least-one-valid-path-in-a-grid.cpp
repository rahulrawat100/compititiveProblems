class Solution {
public:
    int m;
    int n;
    int calc(vector<vector<int>>& grid, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>& pq, vector<vector<int>>& trav)
    {
        int curr=pq.top().first;
        while(pq.size()>0&&pq.top().first==curr)
        {
           // cout<<pq.size()<<endl;;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int z = pq.top().first;
           // cout<<x<<"  "<<y<<endl;
             pq.pop();
          //   cout<<trav.size()<<"  "<<trav[0].size()<<endl;
            if(x<0 || y<0 || x==m || y==n || trav[x][y]==1)
              continue;
             if(x==m-1&&y==n-1)
                return z; 
            //  cout<<x<<" "<<y<<"  "<<z<<endl;  
              vector<int> D(4, 1);
              D[grid[x][y]-1]--;
             trav[x][y]=1;
            pq.push({curr+D[0],{x, y+1}});
            pq.push({curr+D[1],{x, y-1}});
            pq.push({curr+D[2],{x+1, y}});
            pq.push({curr+D[3],{x-1, y}});  
    
        }
                   // cout<<"**"<<endl;
        return calc(grid, pq, trav);
    }

    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
       pq.push({0, {0, 0}});
       vector<vector<int>> trav(m, vector<int>(n, -1));
       return calc(grid, pq, trav);
    }
};