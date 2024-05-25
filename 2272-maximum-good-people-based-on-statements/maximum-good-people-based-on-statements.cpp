class Solution {
public:
    int calc(vector<vector<int>>& statements, int i, vector<int>& status)
    {
        if(i== statements.size())
           return 0;
         else
         {
            // stating person is bad
            int res=INT_MIN;
            if(status[i]!=1)
            {
                int orig=status[i];
                status[i]=0;
               res = calc(statements, i+1, status);
               status[i]=orig;
            }
            if(status[i]==0)return res;
            vector<int> newstatus=status;

            //checking statements if person is good
            for(int j=0; j<statements[i].size();j++)
            {
                if(status[j]==2|| statements[i][j] == 2|| status[j]==statements[i][j])
                  {
                      if(statements[i][j]!=2)
                      {
                         newstatus[j]=statements[i][j];
                      }
                  }
                  else
                     return status[i]==1?INT_MIN:res;
            }
            newstatus[i]=1;
            if(status[i]==1)
               return 1+calc(statements, i+1, newstatus);
             return max(res, 1+calc(statements, i+1, newstatus));
         }  
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        vector<int> status(n, 2);
        return calc(statements, 0, status);
    }
};