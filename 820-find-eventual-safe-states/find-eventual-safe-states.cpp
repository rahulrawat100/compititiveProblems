class Solution {
public:
    bool IsSafe(vector<vector<int>>& adj, int i, vector<bool>& trav, vector<int> &DP)
    {
        if(trav[i])
           return false;
        if(adj[i].size()==0)
           return true;
        if(DP[i]!=-1)
           return DP[i]==1;   
        else
        {
            trav[i]=true;
            for(int j=0; j<adj[i].size();j++)
            {
                if(!IsSafe(adj, adj[i][j], trav, DP))
                {
                    trav[i]=false;
                    DP[i]=0;
                    return false;
                }
            }
            trav[i]=false;
            DP[i]=1;
            return true;
        }   
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> trav(n);
        vector<int> res;
        vector<int> DP(n, -1);
        for(int i=0; i<n; i++)
        {
           if(IsSafe(graph, i, trav, DP))
              res.push_back(i);
        }
        return res;
    }
};