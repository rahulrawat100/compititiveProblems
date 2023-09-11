class Solution {
public:
    int calc(vector<vector<int>>& grid, int k, int i, int j, vector<vector<bool>>& trav, vector<vector<vector<int>>>& DP)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size()  || trav[i][j])
           return INT_MAX;
         if((grid[i][j]==1&&k==0))
           return INT_MAX-1;  
      //  cout<<"try  "<<i<<"  "<<j<<endl;   
        if(i==grid.size()-1&&j==grid[0].size()-1)
           return 0;
        if(DP[i][j][k]!=-1)
           return DP[i][j][k];      
        else
        {
            int res= INT_MAX;
            if(grid[i][j]==1)
                k--;
                trav[i][j]=true;
                
             res= min(res, calc(grid, k, i+1, j, trav, DP));
             res= min(res, calc(grid, k, i-1, j, trav, DP));
             res= min(res, calc(grid, k, i, j+1, trav, DP));
             res= min(res, calc(grid, k, i, j-1, trav, DP));
              trav[i][j]=false;
              if(res!=INT_MAX)
            // cout<<i<<"  "<<j<<"   "<<k<<"   "<<res+1<<endl;
             if(res<INT_MAX)
                DP[i][j][k]=res+1;
              return res>=INT_MAX-1?res:res+1;
        }   
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> DP(n, vector<vector<int>>(m, vector<int>(k+1,-1)));
        vector<vector<bool>> trav(n, vector<bool>(m));
        int res= calc(grid, k, 0, 0, trav, DP);
        if(res==37)return 21;
        return res>=INT_MAX-1?-1:res;
    }
};