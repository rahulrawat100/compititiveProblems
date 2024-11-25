class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        vector<string> S(k, "");
        vector<string> T(k, "");
        int n= s.size();
        int l = n/k;
        for(int i=0;i<n;i+=l)
        {
            for(int j=i;j<i+l;j++)
            {
                S[i/l]+=s[j];
                 T[i/l]+=t[j];
            }
        }

        sort(S.begin(), S.end());
        sort(T.begin(), T.end());

        for(int i=0; i<S.size();i++)
        {
            for(int j=0;j<l;j++)
            {
                if(S[i][j]!=T[i][j])
                    return false;
            }
        }
        return true;
    }
};