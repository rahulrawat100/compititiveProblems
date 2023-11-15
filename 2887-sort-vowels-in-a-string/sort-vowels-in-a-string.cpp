class Solution {
public:
    string sortVowels(string s) {
        vector<char> D;
        vector<int> E;
        int n = s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U')
            {
               D.push_back(s[i]);
               E.push_back(i);
            }
        }
        sort(D.begin(), D.end());
        for(int i=0; i<D.size(); i++)
        {
            //cout<<D[i].first<<endl;
            s[E[i]]=D[i];
        }
        return s;
    }
};