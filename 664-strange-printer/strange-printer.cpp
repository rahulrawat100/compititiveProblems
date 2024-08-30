class Solution {
public:
        int DP[101][101];
    int calc(vector<int>& groups, int i, int j)
    {
    //    cout<<i<<"  "<<j<<endl;
        if(i>j)
           return 0;
        else if(i==j)
           return 1;
       if(DP[i][j]!=-1)
         return DP[i][j];   
        else
        {
            int res=1+calc(groups, i+1, j);
            for(int k=i+1; k<=j; k++)
            {
                if(groups[i]==groups[k])
                  res=min(res, calc(groups, i+1, k-1)+calc(groups, k, j));
            }
            return DP[i][j]=res;
        }      
    }
    int strangePrinter(string s) {
       vector<int> groups;
       int n =s.size();
       memset(DP, -1, sizeof(DP));
       groups.push_back(s[0]-'a');
       int curr=s[0]-'a';
       int ind =0;
       for(int i=0; i<n; i++)
       {
          int x = s[i]-'a';
          if(curr==x)
             continue;
          else
          {
            groups.push_back(x);
            ind++;
            curr=x;
          }   
       }

       return calc(groups, 0, groups.size()-1);

    }
};