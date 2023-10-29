class Solution {
public:
    int calc(vector<vector<int>>& adj, vector<int>& coins, int k, int i, vector<bool>& trav, int div, vector<vector<int>>& DP)
    {
        int d=pow(2, div);
        if(trav[i] || div>=15)
            return 0;
        if(adj[i].size()==0)
            return max(coins[i]/div-k, coins[i]/(2*d));
        if(DP[i][div]!=-1)
           return DP[i][div];    
        else
        {
            trav[i]=true;
            long long res1=0;
            long long res2=0;
            for(int j=0; j<adj[i].size(); j++)
            {
                res1+=calc(adj, coins, k, adj[i][j], trav, div, DP);
                if(coins[i]/d-k<=coins[i]/(2*d))
                res2+=calc(adj, coins, k, adj[i][j], trav, div+1, DP);
            }
            int r= max(coins[i]/d-k+res1, coins[i]/(2*d)+res2);
           // cout<<i<<"  "<<r<<endl;
            trav[i]=false;
            return DP[i][div]=r;
        }
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> trav(n);
        vector<vector<int>> DP(n, vector<int>(15, -1));
        return calc(adj, coins, k, 0, trav, 0, DP);
        
    }
};

    //     0

    //  1    2   4

    //        3   