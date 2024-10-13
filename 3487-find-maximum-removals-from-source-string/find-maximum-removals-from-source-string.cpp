class Solution {
public:
    int calc(string& source, string& pattern, unordered_set<int>& st,  int i, int j, vector<vector<int>>& DP)
    {
        if(i==source.size()&&j==pattern.size())
           return 0;
        if(DP[i][j]!=-1)
           return DP[i][j];   
        if(j==pattern.size())
        {
            if(st.find(i)!=st.end())
               return DP[i][j]=1+calc(source, pattern, st, i+1, j, DP);
            else
               return DP[i][j]=calc(source, pattern, st, i+1, j, DP);
        }
        if(i==source.size())
           return INT_MIN;   
        else
        {
            int res=INT_MIN;
            if(st.find(i)!=st.end())
               res =max(res, 1+calc(source, pattern, st, i+1, j, DP));
            if(source[i]==pattern[j])
               res =max(res, calc(source, pattern, st, i+1, j+1, DP));
             else  
               res= max(res, calc(source, pattern, st, i+1, j, DP));     
            return DP[i][j]=res;
        }   
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        unordered_set<int> st;
        int n = targetIndices.size();
        for(int i=0; i<n;i++)
        {
            st.insert(targetIndices[i]);
        }
        vector<vector<int>> DP(source.size()+2, vector<int>(pattern.size()+2, -1));
        return calc(source, pattern, st, 0, 0, DP);
    }
};