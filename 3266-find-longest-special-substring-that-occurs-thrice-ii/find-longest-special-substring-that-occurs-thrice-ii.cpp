class Solution {
public:
    int maximumLength(string s) {
        int n =s.size();
        
        vector<vector<int>> D(26);
        
        for(int i=0; i<n;)
        {
            int j=i+1;
            while(j<n&&s[i]==s[j])
            {
                j++;
            }
            D[s[i]-'a'].push_back(j-i);
            i=j;
        }
        int res=-1;
        for(int i=0; i<26; i++)
        {
            unordered_map<int, int> E;
            int mx=INT_MIN;
            
            for(int j=0; j<D[i].size(); j++)
            {
                mx=max(mx, D[i][j]);
                E[D[i][j]]++;
            }
            int ans=0;
            for(auto it:E)
            {
                //cout<<it.first<<"  "<<it.second<<endl;
                if(it.second>2)
                    ans=max(ans, it.first);
                else if(it.second==2)
                    ans=max(ans, it.first-1);
                else if(E[it.first-1]>0)
                    ans=max(ans, it.first-1);
                    
            }
            if(mx>2)
                ans=max(ans, mx-2);
            if(ans>0)res=max(res, ans);
        }
        return res;
    }
};