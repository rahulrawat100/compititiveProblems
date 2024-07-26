class Solution {
public:
    int calc(vector<vector<pair<int,int>>>& adj, priority_queue<pair<int, int>>& pq, vector<bool>& trav)
    {
        if(pq.size()==0 || pq.top().first<0)
           return 0;
        else
        {
            int d = pq.top().first;
            int res=0;
            while(!pq.empty() && pq.top().first==d)
            {
                pair<int, int> p = pq.top();
                pq.pop();
               if(trav[p.second])
                  continue;
                res++;
                trav[p.second]=true;
                for(int j=0; j<adj[p.second].size(); j++)
                {
                    pq.push({d-adj[p.second][j].second, adj[p.second][j].first});
                }
            }
            return res+calc(adj, pq, trav);
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
            vector<bool> trav(n);
            priority_queue<pair<int, int>> pq;
            pq.push({distanceThreshold, i});
           int curr = calc(adj, pq, trav);
           //cout<<i<<" "<<curr<<endl;
           if(curr<conn)
           {
             city=i;
             conn=curr;
           }
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