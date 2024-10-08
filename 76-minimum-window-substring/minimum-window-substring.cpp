class Solution {
public:
    bool IsMatch(vector<int>& freq_t, vector<int>& freq)
    {
        for(int i=0; i<100; i++)
        {
            if(freq_t[i]>freq[i])
               return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n =s.size();
        int m=t.size();
        if(n<m)return "";
        vector<int> freq_t(100, 0);

        for(int i=0; i<m; i++)
        {
            freq_t[t[i]-'A']++;
        }
        cout<<"**"<<endl;
        vector<int> freq(100, 0);

        int i=0; 
        int j=0;
        int resi=0;
        int resj=n;
        while(j<n)
        {
          //  cout<<i<<"  "<<j<<endl;
            while(j<n&&!IsMatch(freq_t, freq))
            {
                freq[s[j]-'A']++;
                j++;
            }

            while(i<j&&IsMatch(freq_t, freq))
            {
                if(j-i-1<resj-resi)
                {
                  //  cout<<i<<"  "<<j<<endl;
                    resj=j-1;
                    resi=i;
                }
                freq[s[i]-'A']--;
                i++;
            }
        }

        if(resj==n)
           return "";
        return s.substr(resi, resj-resi+1);
    }
};