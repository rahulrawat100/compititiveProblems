class Solution {
public:
    int getpar(vector<int>& par, int x)
    {
        if(par[x]==x)
          return x;
        else
          return par[x]=getpar(par, par[x]);  
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int m = edges.size();
        vector<int> par(n);
        vector<int> D(n);
        for(int i=0; i<n; i++)
        {
            par[i]=i;
            D[i]=INT_MAX;
        }
        for(int i=0; i<m; i++)
        {
            int X = getpar(par, edges[i][0]);
            int Y = getpar(par, edges[i][1]);
            if(X!=Y)
            {
                par[X]=Y;
                D[Y]=D[Y]&D[X];
            }
            D[Y]=D[Y]&edges[i][2];
        }
        vector<int> res;
        for(int i=0; i<query.size(); i++)
        {
            int X = getpar(par, query[i][0]);
            int Y = getpar(par, query[i][1]);

            if(X==Y)
              res.push_back(D[X]);
            else
              res.push_back(-1);  
        }
        return res;
    }
};