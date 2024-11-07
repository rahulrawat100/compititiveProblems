class Solution {
public:
    int mod = pow(10, 9)+7;
    void Calc(vector<vector<pair<int, int>>>& adj, vector<int>& SDL, priority_queue<pair<int, int>>& pq)
    {
        int n = adj.size();
        while(!pq.empty())
        {
            auto [wt, node]=pq.top();
            pq.pop();
            for(auto [v, edgeweight] : adj[node])
            {
               if(SDL[node]+edgeweight<SDL[v])
               {
                  SDL[v]=SDL[node]+edgeweight;
                  pq.push({-SDL[v], v});
               }
            }
        }
    }

    int calc(vector<vector<pair<int, int>>>& adj, int i, int mint, vector<int>& SDL, vector<int>& DP)
    {
        
          if(SDL[i]<=mint)
            return 0;
          if(i==1)
            return 1;  
          if(DP[i]!=-1)
            return DP[i];  
          else
          {
              int res=0;
              for(int j=0; j<adj[i].size(); j++)
              {
                  res += calc(adj, adj[i][j].first, SDL[i], SDL, DP);
                  res%=mod;
              }
              return DP[i]=res%mod;
          }  
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> SDL(n+1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<edges.size(); i++)
        {
            int u= edges[i][0];
            int v = edges[i][1];
            int w= edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, n});
        SDL[n]=0;
        Calc(adj, SDL, pq);
        vector<int> DP(n+1, -1);
        return calc(adj, n, -1, SDL, DP);

    }
};