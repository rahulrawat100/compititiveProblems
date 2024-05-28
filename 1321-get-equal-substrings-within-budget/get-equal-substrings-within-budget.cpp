class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n =s.size();
        vector<int> D(n);
        for(int i=0; i<n; i++)
        {
           D[i]=abs(s[i]-t[i]);
        }

        int res=0;
        int curr=0;
        int i=0;
        int j=0;

        while(j<n)
        {
            if(curr<=maxCost)
            {
                curr+=D[j];
                j++;
                res=max(res, j-i-1);
            }
            else
            {
                curr-=D[i];
                i++;
            }
        }
        if(curr>maxCost)return res;
        return max(res, j-i);
    }
};