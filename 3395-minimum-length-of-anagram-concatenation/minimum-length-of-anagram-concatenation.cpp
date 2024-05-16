class Solution {
public:
    bool check(vector<vector<int>>& D, int len)
    {
        int prev=0;
        int n=D.size();
        for(int i=len; i<D.size(); i+=len)
        {
            for(int j=0; j<26; j++)
            {
                int f=D[i][j]-D[prev][j];
                int t=D[n-1][j];
                if(f==0&&t==0)
                   continue;
                if(f==0&&t!=0)return false;   
                if(t%f!=0 ||t/f!=(n-1)/len)
                  return false;
            }
            prev=i;
        }
        return true;

    }
    int minAnagramLength(string s) {
        int n=s.size();
        vector<vector<int>> DP(n+1, vector<int>(26, 0));
        for(int i=0; i<n; i++)
        {
            int ind = s[i]-'a';
            for(int j=0; j<26; j++)
            {
                DP[i+1][j]=DP[i][j];
            }
            DP[i+1][ind]=DP[i][ind]+1;
        }
        vector<int> freq(26, 0);
        for(int i=1; i<=n; i++)
        {
           if(n%i==0&&check(DP, i))
             return i;
        }
        return n;
    }
};