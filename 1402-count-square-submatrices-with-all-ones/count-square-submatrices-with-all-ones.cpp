class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> CumMat(m, vector<int>(n, 0));


        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0&&j==0)
                   CumMat[i][j]=matrix[i][j];
                else if(i==0)
                    CumMat[i][j]=CumMat[i][j-1]+matrix[i][j];    
                else if(j==0)
                    CumMat[i][j]=CumMat[i-1][j]+matrix[i][j];
                else
                    CumMat[i][j]=CumMat[i][j-1]+CumMat[i-1][j]-CumMat[i-1][j-1]+matrix[i][j];                
            }
        }

        int res=0;
        for(int s=1; s<=min(m, n);s++)
        {
            for(int i=s-1; i<m;i++)
            {
                for(int j=s-1; j<n;j++)
                {
                    int i1=i-s;
                    int j1=j-s;
                    int ones;
                    if(i1<0 && j1<0)
                    ones=CumMat[i][j];
                    else if(i1<0)
                    ones=CumMat[i][j]-CumMat[i][j1];
                    else if(j1<0)
                    ones=CumMat[i][j]-CumMat[i1][j];
                    else
                    ones=CumMat[i][j]+CumMat[i1][j1]-CumMat[i][j1]-CumMat[i1][j];  
                    if(ones == s*s)
                       res++;  
                }
            }
        }
        return res;


        
    }
};