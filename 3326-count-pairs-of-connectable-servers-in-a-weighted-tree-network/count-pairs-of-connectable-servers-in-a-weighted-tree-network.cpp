class Solution {
public:
    void calc(vector<vector<pair<int, int>>>& adj, int i, vector<bool>& trav, vector<int>& res, int curr)
    {
        if(trav[i])
            return;
        else
        {
            res.push_back(curr);
            trav[i]=true;
            
            for(int j=0; j<adj[i].size(); j++)
            {
                calc(adj, adj[i][j].first, trav, res, curr+adj[i][j].second);
            }
            trav[i]=false;
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int m = edges.size();
        
        vector<vector<pair<int, int>>> adj(m+1);
        
        for(int i=0; i<m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int n=m+1;
        vector<int> res(m+1, 0);
        vector<bool> trav(m+1);
        for(int i=0; i<n; i++)
        {
            trav[i]=true;
            vector<vector<int>> D(adj[i].size());
            for(int j=0; j<adj[i].size(); j++)
            {
                calc(adj, adj[i][j].first, trav, D[j], adj[i][j].second);
            }
            
            for(int j=0; j<D.size(); j++)
            {
                for(int k=j+1; k<D.size(); k++)
                {
                    for(int p=0; p<D[j].size(); p++)
                    {
                        for(int s=0; s<D[k].size(); s++)
                        {
                            if(D[j][p]%signalSpeed==0&&D[k][s]%signalSpeed==0)
                                res[i]++;
                        }
                    }
                }
            }
            trav[i]=false;
        }
        return res;
    }
};