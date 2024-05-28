class Solution {
public:
    long long numberOfPairs(vector<int>& n1, vector<int>& n2, int k) {
        int n = n1.size();
        int m = n2.size();
        vector<int> A;
        for(int i=0; i<n; i++)
        {
            if(n1[i]%k==0)
              A.push_back(n1[i]/k);
        }

        unordered_map<int, int> B;
        for(int i=0; i<m; i++)
        {
            B[n2[i]]++;
        }

        sort(A.begin(), A.end());
        long long res=0;
        long long curr=0;
        unordered_map<int, int> C;
        for(int i=0; i<A.size(); i++)
        {
            if(i>0&&A[i]==A[i-1])
              res+=curr;
            else
            {  
              curr=0;
            for(int j=1;j*j<=A[i];j++)
            {
                if(A[i]%j==0)
                {
                    curr+=B[j];
                    if(j!=A[i]/j)
                       curr+=B[A[i]/j];
                }
            }
            //cout<<A[i]<<"  "<<curr<<endl;
            res+=curr;
            }
        }
        return res;
    }
};