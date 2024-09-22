class Solution {
public:
    bool check(vector<int>& a, vector<int>& b)
    {
        for(int i=0; i<26; i++)
        {
            if(a[i]<b[i])
              return false;
        }
        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        int m= word2.size();

        vector<int> freq(26, 0);
        int n = word1.size();
        for(int i=0; i<m; i++)
        {
            freq[word2[i]-'a']++;
        }

        long long res=0;
        vector<int> f(26, 0);
        int j=0;
        for(int i=0; i<word1.size()-word2.size()+1; i++)
        {
             for(; j<n;j++)
             {
                f[word1[j]-'a']++;
                if(check(f, freq))
                {
                    res+=n-j;
                    f[word1[j]-'a']--;
                    break;
                }
             }
             f[word1[i]-'a']--;
        }
        return res;
    }
};