class Solution {
public:
    bool IsVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o'  || ch=='u')
           return true;
        return false;
    }
    int IsGood(string s)
    {
        int m = s.size();
        if(IsVowel(s[0])&&IsVowel(s[m-1]))
           return 1;
        return 0;   
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> cum(n+1, 0);

        for(int i=1; i<=n; i++)
        {
            cum[i]=cum[i-1]+IsGood(words[i-1]);
        }

        vector<int> res;

        for(int i=0; i< queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            res.push_back(cum[r+1]-cum[l]);
        }
        return res;
    }
};