class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<vector<long long>> DP(m, vector<long long>(n));
        long long res=0;
        for(int i=0; i<n;i++)
        {
             DP[0][i]=points[0][i];
             res=max(res, DP[0][i]);
        }
        for(int i=1; i<m; i++)
        {
            long long lmaxI= 0;
            DP[i][0]=DP[i-1][0]+points[i][0];
            for(int j=1;j<n;j++)
            {
                if(DP[i-1][lmaxI]-j+lmaxI<DP[i-1][j])
                {
                    DP[i][j]=DP[i-1][j]+points[i][j];
                    lmaxI=j;
                }
                else
                {
                    DP[i][j]=points[i][j]+DP[i-1][lmaxI]-j+lmaxI;
                }
                if(i==m-1)
                   res=max(res, DP[i][j]);
            }

            long long rmaxI=n-1;
            DP[i][n-1]=max(DP[i][n-1], DP[i-1][n-1]+points[i][n-1]);
            for(int j=n-2; j>=0; j--)
            {
               if(DP[i-1][rmaxI]-rmaxI+j<DP[i-1][j])
                {
                    DP[i][j]=max(DP[i][j],DP[i-1][j]+points[i][j]);
                    rmaxI=j;
                }
                else
                {
                    DP[i][j]=max(DP[i][j], points[i][j]+DP[i-1][rmaxI]-rmaxI+j);
                }
                if(i==m-1)
                   res=max(res, DP[i][j]);
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                res =max(res, DP[i][j]);
              //  cout<<DP[i][j]<<"    ";
            }
            cout<<endl;
        }
        
        return res;

    }
};

/*
[[4,3,2,1]
,[1,4,3,0]
,[0,0,1,5]
,[1,5,3,4]
,[0,3,3,4]]
*/