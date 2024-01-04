class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n =values.size();
        int res=0;
        vector<int> A, B; 
        for(int i=0; i<n; i++)
        {
           A.push_back(values[i]+i);
           B.push_back(values[i]-i);
        }
        for(int i=1; i<n; i++)
        {
           A[i]=max(A[i-1], A[i]);
        }
        for(int i=n-2; i>=0; i--)
        {
           B[i]=max(B[i+1], B[i]);
        }
        for(int i=0; i<n-1; i++)
        {
           res=max(res, A[i]+B[i+1]);
        }


        return res;
    }
};