class Solution {
public:
    int calc(vector<vector<int>>& grid,queue<pair<pair<int, int>, int>>& Q, vector<vector<vector<bool>>>& trav)
    {
        if(Q.size()==0 )
          return INT_MAX;
        else
        {
            int s= Q.size();
            queue<pair<pair<int, int>, int>> trv;
            while(s>0)
            { 
                int x = Q.front().first.first;
                int y = Q.front().first.second;
                int k =Q.front().second;
                s--;
                  Q.pop();
                if(x<0 ||y<0 ||x==grid.size() || y==grid[0].size() ||  trav[x][y][k] )
                  continue;
                   trv.push({{x, y},k});
                  if(x==grid.size()-1&&y==grid[0].size()-1)
                    return 0;

                  if(grid[x][y]==1)
                  {
                     if(k>0)
                     {
                      trav[x][y][k]=true; 
                     Q.push({{x+1, y}, k-1});
                     Q.push({{x-1, y}, k-1});
                     Q.push({{x, y+1}, k-1});
                     Q.push({{x, y-1}, k-1});
                     }
                  }
                  else
                  {
                    trav[x][y][k]=true;
                    Q.push({{x+1, y}, k});
                     Q.push({{x-1, y}, k});
                     Q.push({{x, y+1}, k});
                     Q.push({{x, y-1}, k});
                  }
            } 
            int res= calc(grid, Q, trav);
            while(!trv.empty())
            {
                int x = trv.front().first.first;
                int y = trv.front().first.second;
                int k =trv.front().second;
             //   trav[x][y][k]=false;
                trv.pop();
            }
            return res==INT_MAX?res:res+1;
        }  
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<vector<bool>>> trav(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(k+1)));
        q.push({{0, 0}, k});
        int x= calc(grid,  q, trav);
        return x==INT_MAX?-1:x;
    }
};
/*
[[0,0]
,[1,0]
,[1,0]
,[1,0]
,[1,0]
,[1,0]
,[0,0]
,[0,1]
,[0,1]
,[0,1]
,[0,0]
,[1,0]
,[1,0]
,[0,0]]*/