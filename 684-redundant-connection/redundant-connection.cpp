class Solution {
public:
    int getpar(vector<int>& par, int x)
    {
        if(par[x]==x)
          return x;
        else
          return par[x]=getpar(par, par[x]);  
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
       vector<int> par(n+1);
       for(int i=1; i<=n; i++)
       {
          par[i]=i;
       }
        for(int i=0; i<n; i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            int U=getpar(par, u);
            int V=getpar(par, v);
            if(U==V)
               return edges[i];
             else
               par[U]=V;  
        }
        return {0, 0};
    }
};