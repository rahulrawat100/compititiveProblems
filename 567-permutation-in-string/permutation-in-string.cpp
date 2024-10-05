class Solution {
public:
bool HasEqualFreq(vector<int>& freq_s1, vector<int>& freq_substr)
{
   for(int i=0; i<26; i++)
   {
      if(freq_s1[i]!=freq_substr[i])
         return false;
   }
   return true;
}
    bool checkInclusion(string s1, string s2) {
       vector<int> freq_s1(26, 0);
    int m = s1.size();
    int n = s2.size();

    for(int i=0; i<m; i++)
    {  
       freq_s1[s1[i]-'a']++;
    }

    vector<int> freq_substr(26, 0);

    int i=0;
    int j=0;

    while(j<n)
   {
      while(j<n&&j-i<m)
      {
        freq_substr[s2[j]-'a']++;
        j++;
      }
      if(j-i<m)
         break;
      if(HasEqualFreq(freq_s1, freq_substr))
         return true;
      freq_substr[s2[i]-'a']--;
      i++;
   }
    return false; 
    }
};