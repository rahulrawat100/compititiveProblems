class Solution {
public:
    int appendCharacters(string s, string t) {
       int m=s.size();
       int n=t.size();
       int j=0;
       int i=0;
       for(; i<n&&j<m;)
       {
            if(s[j]==t[i])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
       } 
       return n-i;
    }
};