class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> D(26);
        for(int i=0; i<chars.size(); i++)
        {
            D[chars[i]-'a']++;
        }

        int n = words.size();
        vector<int> E(26);
        int res=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                E[words[i][j]-'a']++;
            }
             bool has=true;
            for(int j=0; j<26; j++)
            {
               if(E[j]>D[j])
                  has=false;
                 E[j]=0; 
            }
            if(has)res+=words[i].size();
        }
        return res;
    }
};