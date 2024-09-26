class Solution {
public:
    int calc(string& s)
    {
        int n = s.size();
        int res=-1;
        vector<int> lse(n, 0);
        for(int i=1; i<n; i++)
        {
           // cout<<i<<endl;
            int j=lse[i-1];
           while(j>0&&s[i]!=s[j])
           {
               j=lse[j-1];
           }
           if(s[i]==s[j])
              j++;
            if(j>0)
               res=max(res,j);  
            lse[i]=j;
        }
        return lse[n-1];
    }
    string longestPrefix(string s) {
        int n = s.size();

        int res=calc(s);

        string ans="";
        
        for(int i=0; i<res;i++)
        {
            ans+=s[i];
        }
        return ans;     
    }
};