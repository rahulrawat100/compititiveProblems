class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> D;
        int n =s.size();
        int res=0;
        for(int i=0; i<n; i++)
        {
            D[s[i]]++;
            if(D[s[i]]==2)
            {
                D[s[i]]-=2;
                res+=2;
            }
        }
        return res<n?res+1:res;
    }
};