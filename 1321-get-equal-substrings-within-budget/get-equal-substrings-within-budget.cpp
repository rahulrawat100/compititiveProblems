class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> D(s.size()+1, 0);
        for(int i=0; i<s.size(); i++)
        {
           D[i+1]=D[i]+abs(s[i]-t[i]);
        }

        int res=0;

        for(int i=1; i<=s.size(); i++)
        {
            int tar = D[i]-maxCost;
            auto it = lower_bound(D.begin(), D.end(), tar);
            int dis = it-D.begin();
            res=max(res, i-dis);

        }
        return res;
    }
};