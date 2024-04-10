class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++)
        {
            int a = pre[i][0];
            int b = pre[i][1];
            adj[b].push_back(a);
            deg[a]++;
        }

        queue<int> q;

        vector<int> res;
            for(int i=0; i<n; i++)
            {
                if(deg[i]==0)
                {
                   q.push(i);
                   res.push_back(i);
                }
            }
        while(res.size()<n)
        {
            queue<int> t;
            if(q.empty())return {};
            while(!q.empty())
            {
                for(int i=0; i<adj[q.front()].size(); i++)
                {
                    deg[adj[q.front()][i]]--;
                    if(deg[adj[q.front()][i]]==0)
                       {
                          t.push(adj[q.front()][i]);
                          res.push_back(adj[q.front()][i]);
                       }
                }
                q.pop();
            }
            q=t;
        }
        return res;
    }
};