bool compare(vector<int>& A, vector<int>& B)
    {
        if(A[0]<B[0])
           return true;
        if(A[0]>B[0])
           return false;   
        return A[1]>B[1];     
    }
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n =envelopes.size();
        vector<int> D;
        int ans=1;
        sort(envelopes.begin(), envelopes.end(), compare);
        // for(int i=0; i<n; i++)
        // {
        //     cout<<envelopes[i][0]<<"  "<<envelopes[i][1]<<endl;
        // }
        D.push_back(envelopes[0][1]);
      
        for(int i=1; i<n; i++)
        {
            if(D.back()<envelopes[i][1])
               D.push_back(envelopes[i][1]);
            else
            {
               int ind = lower_bound(D.begin(), D.end(), envelopes[i][1])-D.begin();
               D[ind]=envelopes[i][1];
            }   
        }
        return D.size();

    }
};