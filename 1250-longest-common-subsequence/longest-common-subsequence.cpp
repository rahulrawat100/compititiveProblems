class Solution {
public:
    int lcs(string& s1, string& s2, int i, int j, vector<vector<int>>& DP)
    {
        if(i<0 || j<0)
          return 0;
        else if(DP[i][j]!=-1)
          return DP[i][j];  
        else if(s1[i]==s2[j])
          return DP[i][j]=1+lcs(s1, s2, i-1, j-1, DP);
        else
          return DP[i][j]=max(lcs(s1, s2, i-1, j, DP), lcs(s1, s2, i, j-1, DP));    
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> DP(m, vector<int>(n, -1));
        return lcs(text1, text2, m-1, n-1, DP);
    }
};