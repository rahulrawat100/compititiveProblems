class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> ShortPath(n, vector<int>(n, INT_MAX));

        int m = edges.size();
        for(int i=0; i<n; i++)
        {
            ShortPath[i][i]=0;
        }
        for(int i=0; i<m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            ShortPath[u][v]=w;
            ShortPath[v][u]=w;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                   if(ShortPath[j][i]<INT_MAX && ShortPath[i][k]<INT_MAX)
                   { 
                    ShortPath[j][k]= min(ShortPath[j][k], ShortPath[j][i] + ShortPath[i][k]);
                   }
                }
            }
        }
        int conn=INT_MAX;
        int city=n-1;
        for(int i=n-1; i>=0; i--)
        {
            int tot=0;
            for(int j=0; j<n; j++)
            {
                if(ShortPath[i][j]<=distanceThreshold)
                  tot++;
            }
            if(tot<conn)
            {
                conn=tot;
                city=i;
            }
        }
        return city;
    }
};