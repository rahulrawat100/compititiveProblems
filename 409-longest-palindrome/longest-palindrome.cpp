class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> D;
        int n =s.size();

        for(int i=0; i<n; i++)
        {
            D[s[i]]++;
        }

        int res=0;
        bool odd=false;
        for(auto i:D)
        {
             if(i.second%2==1)
             {
                res+=i.second-1;
                odd=true;
             }
             else
               res+=i.second;
        }
        return odd?res+1:res;
    }
};