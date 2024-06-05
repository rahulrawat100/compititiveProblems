class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> D(26, INT_MAX);
        for(int i=0; i<n; i++)
        {
            vector<int> E(26, 0);
            for(int j=0; j<words[i].size();j++)
            {
                E[words[i][j]-'a']++;
            }
            for(int j=0; j<26;j++)
            {
                D[j]=min(D[j], E[j]);
            }
        }

        vector<string> res;

        for(int i=0;i<26;i++)
        {
            string ans="";
            ans+=(char)('a'+i);
            while(D[i]>0)
            {
                res.push_back(ans);
                D[i]--;
            }
        }
        return res;

    }
};