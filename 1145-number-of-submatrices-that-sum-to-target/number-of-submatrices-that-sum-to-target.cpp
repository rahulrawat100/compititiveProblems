class Solution {
public:
    int calc(vector<vector<int>>& Cumulative, int x, int y, int a, int b)
    {
        x--;
        y--;
        if(x<0 && y<0)
          return Cumulative[a][b];
        else if(x<0)
          return Cumulative[a][b]-Cumulative[a][y];
        else if(y<0)
          return Cumulative[a][b]-Cumulative[x][b]; 
        else
          return Cumulative[a][b]+Cumulative[x][y]-Cumulative[a][y]-Cumulative[x][b];     
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int res=0;
        vector<vector<int>> Cumulative(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            int s=0;
            for(int j=0; j<m; j++)
            {
                s+=matrix[i][j];
                if(i>0)
                  Cumulative[i][j]=Cumulative[i-1][j]+s;
                else
                  Cumulative[i][j]=s;  
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int k=i; k<n; k++)
                {
                    for(int l=j; l<m; l++)
                    {
                        int sum= calc(Cumulative, i, j, k, l);
                        if(sum==target)
                           res++;  
                    }
                }

            }
        }
        return res;
    }
};
