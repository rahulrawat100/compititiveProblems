class Solution {
public:
    bool check(string s, string t, int k)
    {
        int i=0;
        for(; i<INT_MAX; i++)
        {
            if(k+i==s.size()||i==t.size())
                 break;
            if(s[k+i]!=t[i])
               return false;
        }
        if(i<t.size())return false;
        return true;
    }
    int calc(string s, vector<vector<string>>& D, int i, vector<int>& DP)
    {
        if(i>=s.size())
           return 0;
        else if (DP[i]!=-1)
           return DP[i];   
         else
         {
             int res=INT_MAX;
             for(int j=0; j<D[s[i]-'a'].size(); j++)
             {
                if(check(s, D[s[i]-'a'][j], i))
                {
                    // cout<<D[s[i]-'a'][j]<<endl;
                    int t = D[s[i]-'a'][j].size();
                  res=min(res, calc(s, D, i+t, DP));
                }
             }
            //  cout<<1<<"  "<<endl;
             res= min(res, 1+calc(s, D, i+1, DP));
            //  cout<<"   "<<1<<endl;
             return DP[i]=res;
         }  
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<vector<string>> Dict(26);

        for(int i=0; i<dictionary.size(); i++)
        {
            Dict[dictionary[i][0]-'a'].push_back(dictionary[i]);
        }
        vector<int> DP(s.size(), -1);
        return calc(s, Dict, 0, DP);

    }
};