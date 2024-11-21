class Solution {
public:
    void setter(vector<vector<int>>& NG, int i, int j)
    {
        int m = NG.size();
        int n = NG[0].size();

        int x=i-1;
        while(x>=0)
        {
            if(NG[x][j]==1 || NG[x][j]==2)
                break;
               NG[x][j]=3;
            x--;   
        }

        x=i+1;

        while(x<m)
        {
            if(NG[x][j]==1 || NG[x][j]==2)
               break;
             NG[x][j]=3;
             x++;  
        }

        int y=j-1;

        while(y>=0)
        {
            if(NG[i][y]==1 || NG[i][y]==2)
                break;
            NG[i][y]=3;
            y--;    
        }

        y=j+1;

        while(y<n)
        {
            if(NG[i][y]==1 || NG[i][y]==2)
               break;
            NG[i][y]=3;
            y++;   
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> NG(m, vector<int>(n, 0));

        for(int i=0; i<walls.size(); i++)
        {
            int x = walls[i][0];
            int y = walls[i][1];
            NG[x][y]=1;
        }

        for(int i=0; i<guards.size(); i++)
        {
            int x = guards[i][0];
            int y = guards[i][1];
            NG[x][y]=2;
        }


        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(NG[i][j]==2)
                  setter(NG, i, j);
            }
        }
        int res=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(NG[i][j]==0)
                  res++; 
            }
        }

        return res;




    }
};