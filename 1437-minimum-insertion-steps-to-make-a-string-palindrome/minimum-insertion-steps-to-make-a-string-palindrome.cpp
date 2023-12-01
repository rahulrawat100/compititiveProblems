class Solution {
public:
   int calc(string& s1, string& s2, int i, int j,  vector<vector<int>>& DP)
   {
       if(i<0 || j<0)
          return 0;
       if(DP[i][j]!=-1)
         return DP[i][j]   ;
       else
         {
             if(s1[i]==s2[j])
                return 1+calc(s1, s2, i-1, j-1, DP);
             return DP[i][j]=max(calc(s1, s2, i-1, j, DP), calc(s1, s2, i, j-1, DP));   
         }   
   }
    int minInsertions(string s) {
        int n = s.size();
        string p="";
        for(int i=n-1; i>=0; i--)
        {
            p+=s[i];
        }
         vector<vector<int>> DP(n, vector<int>(n, -1));
        int pal = calc(s, p, n-1, n-1, DP);
        return n-pal;
    }
};