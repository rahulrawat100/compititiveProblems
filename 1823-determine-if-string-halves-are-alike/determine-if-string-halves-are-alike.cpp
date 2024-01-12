class Solution {
public:
    bool halvesAreAlike(string s) {
        int freq=0;
        int n = s.size();
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='a' ||s[i]=='e'||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U')
               {
                  if(i<n/2)
                      freq++;
                   else
                       freq--;
               } 
    }
               return freq==0;
    }
};