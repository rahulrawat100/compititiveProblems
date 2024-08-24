class Solution {
public:
    int getpar(vector<int>& par, int x)
    {
        if(par[x]==x)
           return par[x];
        else
           return par[x]=getpar(par, par[x]);   
    }

    static int comp(vector<int>& a, vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> sq;

        for(int i=0; i<queries.size(); i++)
        {
            sq.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        }
        
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(sq.begin(), sq.end());
        vector<int> par(n);

        for(int i=0; i<n; i++)
        {
            par[i]=i;
        }

        vector<bool> res(queries.size());
        int j=0;
               //cout<<sq[0].size()<<endl;
        for(int i=0; i<sq.size();i++)
        {
            int u1 = sq[i][1];
            int v1= sq[i][2];
            while(j<edgeList.size() && edgeList[j][2]<sq[i][0])
            {
                int u = edgeList[j][0];
                int v = edgeList[j][1];
                int U = getpar(par, u);
                int V = getpar(par, v);
                par[U]=V;
                j++;  
            }

            int U1 = getpar(par, u1);
            int V1 = getpar(par, v1);

            if(U1==V1)
              res[sq[i][3]]=true;

        }
        return res;
    }
};