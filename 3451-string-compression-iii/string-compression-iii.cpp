class Solution {
public:
    string compressedString(string word) {
        int n = word.size();

        int i=0; 
        string res="";

        while(i<n)
        {
            int j=i;
            while(j<n&&(j-i<9)&&word[i]==word[j])
            {
                j++;
            }
            char dig = (char)(j-i+'0');
            res+=dig;
            res+=word[i];
            i=j;
        }
        return res;
    }
};