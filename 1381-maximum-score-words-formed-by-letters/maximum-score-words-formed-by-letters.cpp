class Solution {
public:
    int calc(vector<vector<int>>& wordF, vector<int>& aval, vector<int>& score, int i)
    {
        if(i==wordF.size())
           return 0;
        else
        {
            int res= INT_MIN;
            res=max(res, calc(wordF, aval, score, i+1));
            for(int j=0; j<26; j++)
            {
                if(aval[j]<wordF[i][j])
                   return res;
            }
            int curr=0;
           for(int j=0; j<26; j++)
            {
                curr+=wordF[i][j]*score[j];
                aval[j]-=wordF[i][j];
            }
            res=max(res, curr+calc(wordF, aval, score, i+1));
            for(int j=0; j<26; j++)
            {
                aval[j]+=wordF[i][j];
            }
            return res;
        }   
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<vector<int>> wordF(n, vector<int>(26, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                wordF[i][words[i][j]-'a']++;
            }
        }

        vector<int> aval(26, 0);

        int m = letters.size();

        for(int i=0; i<m; i++)
        {
            aval[letters[i]-'a']++;
        }
        return calc(wordF, aval, score, 0);
    }
};