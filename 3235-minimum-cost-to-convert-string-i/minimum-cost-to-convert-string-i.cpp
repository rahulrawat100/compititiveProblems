class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> D(26, vector<long long>(26, INT_MAX));

        for(int i=0; i<26; i++)
        {
            D[i][i]=0;
        }

        int m =original.size();

        for(int i=0; i<m; i++)
        {
           int u = original[i]-'a';
           int v = changed[i]-'a';
           long long w = cost[i];
           D[u][v]=min(D[u][v],w);
        }

        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                for(int k=0; k<26; k++)
                {
                    if(j==k)continue;
                    D[j][k]=min(D[j][k], D[j][i]+D[i][k]);
                }
            }
        }

        long long res=0;

        for(int i=0; i<source.size(); i++)
        {
            int u = source[i]-'a';
            int v = target[i]-'a';
            //cout<<u<<"  "<<v<<"  "<<D[u][v]<<endl;
            if(D[u][v]==INT_MAX)return -1;
            res+=D[u][v];
        }
        return res;
    }
};