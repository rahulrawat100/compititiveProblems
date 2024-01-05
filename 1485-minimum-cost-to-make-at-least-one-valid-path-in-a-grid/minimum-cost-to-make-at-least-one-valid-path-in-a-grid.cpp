class Solution {
public:
    bool valid(vector<vector<int>>& grid, int x, int y, int k, vector<vector<int>>& trav)
    {
        int m = grid.size();
        int n = grid[0].size();
       // cout<<"**"<<x<<"  "<<y<<endl;
        if(k<0 || x<0 || y<0 || x==m || y==n ||k<=trav[x][y])
           return false;
        //cout<<x<<"  "<<y<<endl;   
        if(x==m-1 && y==n-1)
        {
            //cout<<x<<"  "<<y<<"  "<<k<<endl;
          return true;
        }
         else
          {
              trav[x][y]=k;
              if(grid[x][y]==1)
                  return valid(grid, x, y+1, k, trav) || valid(grid, x, y-1, k-1, trav) || valid(grid, x+1, y, k-1, trav) || valid(grid, x-1, y, k-1, trav);
              else if(grid[x][y]==2)
                  return valid(grid, x, y+1, k-1, trav) || valid(grid, x, y-1, k, trav) || valid(grid, x+1, y, k-1, trav) || valid(grid, x-1, y, k-1, trav); 
             else if(grid[x][y]==3)
                  return valid(grid, x, y+1, k-1, trav) || valid(grid, x, y-1, k-1, trav) || valid(grid, x+1, y, k, trav) || valid(grid, x-1, y, k-1, trav); 
             else if(grid[x][y]==4)
                  return valid(grid, x, y+1, k-1, trav) || valid(grid, x, y-1, k-1, trav) || valid(grid, x+1, y, k-1, trav) || valid(grid, x-1, y, k, trav);             
          }    
          return false;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<=m+n; i++)
        {
             vector<vector<int>> trav(m, vector<int>(n, -1));
            if(valid(grid, 0, 0, i, trav))
               return i;
        }   
        return m+n;
    }
};