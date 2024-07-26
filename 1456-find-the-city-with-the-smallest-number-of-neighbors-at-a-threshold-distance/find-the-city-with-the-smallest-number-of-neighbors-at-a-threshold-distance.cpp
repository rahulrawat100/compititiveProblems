class Solution {
public:
    int calc(vector<vector<pair<int,int>>>& adj, int dis, int i, vector<int>& trav)
    {
        if(dis<0 || trav[i]>=dis)
          return 0;
        else
        {
             cout<<i<<"  ";
            int res=trav[i]!=-1?0:1;
            trav[i]=dis;
            for(int j=0; j<adj[i].size(); j++)
            {
               res += calc(adj, dis-adj[i][j].second, adj[i][j].first, trav);
            }
            return res;
        }  
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int city=n-1;
        int conn=INT_MAX;
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        for(int i=n-1; i>=0; i--)
        {
            vector<int> trav(n, -1);
           int curr = calc(adj,  distanceThreshold, i, trav);
          // cout<<curr<<endl;
           if(curr<conn)
           {
             city=i;
             conn=curr;
           }
          // cout<<i<<"  "<<city<<endl;
        }
        return city;
    }
};
/*
                      1            10
                 1------------>4----------->5
         10           1
  0------------->1------------>3
         1             1
  0-------------->2---------->3
  */