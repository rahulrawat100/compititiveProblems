class Solution {
public:
    int calc(vector<vector<int>>& grid, queue<pair<int, pair<int, int>>> q1, vector<vector<int>>& trav)
    {
        cout<<"***"<<endl;
        int m = grid.size();
        int n= grid[0].size();
        if(q1.size()==0)
          return INT_MAX;
        else
        {
            int s= q1.size();

            while(s>0)
            {
                int x = q1.front().first;
                int y = q1.front().second.first;
                int k = q1.front().second.second;
                //cout<<x<<"  "<<y<<"  "<<k<<endl;
                 q1.pop();
                 s--;
                if(x<0 || y<0 || x ==m || y==n || k<=trav[x][y])
                  continue;
                if(x==m-1&&y==n-1)
                  return 0;  
                trav[x][y]=k;
                 if(grid[x][y]==1)
                 {
                     if(k>0)
                     {
                         q1.push({x+1, {y, k-1}});
                         q1.push({x-1, {y, k-1}});
                         q1.push({x, {y+1, k-1}});
                         q1.push({x, {y-1, k-1}});
                     }
                 } 
                 else
                 {
                         q1.push({x+1, {y, k}});
                         q1.push({x-1, {y, k}});
                         q1.push({x, {y+1, k}});
                         q1.push({x, {y-1, k}});
                 }
            }

            int res=calc(grid, q1, trav);
            return res==INT_MAX?res:res+1;
        }  
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n= grid[0].size();
         queue<pair<int, pair<int, int>>> q1;
         q1.push({0, {0, k}});
        vector<vector<int>> trav(m, vector<int>(n, -1));
                    int res=calc(grid, q1, trav);
            return res==INT_MAX?-1:res;

    }
};