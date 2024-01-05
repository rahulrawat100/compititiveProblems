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

    int binser(vector<vector<int>>& grid, int A, int B)
    {
        cout<<A<<"  "<<B<<endl;
        int m = grid.size();
        int n = grid[0].size();
        if(A==B)
          return A;
        else
        {
            int mid = A+(B-A)/2;
            vector<vector<int>> trav1(m, vector<int>(n, -1));
            vector<vector<int>> trav2(m, vector<int>(n, -1));
            if(valid(grid, 0, 0, mid, trav1))
            {
                if(!valid(grid, 0, 0, mid-1, trav2))
                   return mid;
                 else
                  return binser(grid,A, mid-1);  
            }
            else
            {
                if(valid(grid, 0, 0, mid+1, trav2))
                   return mid+1;
                 else
                  return binser(grid, mid+1, B);  
            }
            
        }  
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return binser(grid, 0, m+n);
    }
};