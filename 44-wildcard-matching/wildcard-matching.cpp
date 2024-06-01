class Solution {
public:

    bool calc(string& s, string& p, int i, int j,vector<vector<int>>& DP)
    {
        if(i==s.size()&&j==p.size()-1&&p[j]=='*')
           return true; 
        if(i==s.size()&&j==p.size())
           return true;
        else if(i==s.size() || j==p.size())
           return false;  
        if(DP[i][j]!=-1)
           return DP[i][j]==1;   
        else
        {
            bool res;
            if(p[j]=='?')
               res= calc(s, p, i+1, j+1, DP);
            else if(p[j]=='*')
               res= calc(s, p, i, j+1, DP) || calc(s, p, i+1, j, DP);
            else if(p[j]==s[i])
               res= calc(s, p, i+1, j+1, DP);
            else
               res= false;

           DP[i][j]=res?1:0;
           return res;              
        }      
    }
    bool isMatch(string s, string p) {

        string p2="";

        for(int i=0; i<p.size();i++)
        {
            if(i>0&&p[i]==p[i-1]&&p[i]=='*')
              continue;
            p2+=p[i];      
        }
        int m = s.size();
        int n = p2.size();
        vector<vector<int>> DP(m, vector<int>(n, -1));
        return calc(s, p2, 0, 0, DP);
    }
};