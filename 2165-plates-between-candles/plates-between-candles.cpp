class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> plates(n+1, 0);
        vector<int> np(n);
        vector<int> pp(n);
        int p=-1;
        for(int i=0; i<n; i++)
        {
           if(s[i]=='|')
              p=i;
            pp[i]=p;  
        }
        p=n;
        for(int i=n-1; i>=0; i--)
        {
           if(s[i]=='|')
              p=i;
            np[i]=p;  
        }
        for(int i=0; i<n; i++)
        {
            if(s[i]=='*')
               plates[i+1]=plates[i]+1;
             else
               plates[i+1]=plates[i];  
        }

        for(int i=0; i<=n; i++)
        {
            cout<<plates[i]<<"  ";
        }

        vector<int> res;

        for(int i=0; i<queries.size(); i++)
        {
            int a = np[queries[i][0]];
            int b = pp[queries[i][1]];
            if(b-a>1)
              res.push_back(plates[b]-plates[a+1]);
            else
              res.push_back(0);  
        }
        return res;
    }
};