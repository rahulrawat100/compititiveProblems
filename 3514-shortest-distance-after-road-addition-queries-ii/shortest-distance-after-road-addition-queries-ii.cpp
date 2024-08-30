class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> DP(n);

        for(int i=0; i<n-1; i++)
        {
            DP[i]=i+1;
        }
        int m =queries.size();
        int curr=n-1;
        vector<int> res;
        for(int i=0; i<m; i++)
        {
            int u =queries[i][0];
            int v = queries[i][1];

            if(DP[u]==-1 ||DP[u]>=v)
               res.push_back(curr);
            else
            {
                int count=0;

                int j=u;
                while(j<v)
                {
                    j=DP[j];
                    count++;
                }
                
                if(count>1)
                {
                for(j=DP[u];j<v;)
                {
                    int t=DP[j];
                   DP[j]=-1;
                   j=t;
                }
                curr-=(count-1);
                DP[u]=v;
                }
                res.push_back(curr);
            }   
        }
        return res;
    }
};
/*

0  1  2  3  4  5  6

*/