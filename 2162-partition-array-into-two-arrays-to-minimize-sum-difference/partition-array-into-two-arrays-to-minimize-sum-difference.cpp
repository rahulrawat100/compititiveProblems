class Solution {
public:
    void sum(vector<int>& nums, int i, int j, vector<vector<int>>& S, int count, int s)
    {
        if(i==j)
          {
            S[count].push_back(s);
            //cout<<count<<"  "<<s<<endl;
          }
         else
         {
            sum(nums, i+1, j, S, count, s);
            sum(nums, i+1, j, S, count+1, s+nums[i]);
         } 
    }

    int minimumDifference(vector<int>& nums) {
        int n =nums.size();
        int tot=0;
        for(int i=0; i<n; i++)
        {
            tot+=nums[i];
        }
        int m = n/2;
        //sort(nums.begin(), nums.end(), greater<int>());
        vector<vector<int>> L(m+1);
        vector<vector<int>> R(n-m+1);
        sum(nums, 0, m, L, 0, 0);
        sum(nums, m, n, R, 0, 0);
        int res=min(abs(tot-2*L[m][0]), abs(tot-2*R[m][0]));
        for(int i=0; i<R.size(); i++)
        {
            sort(R[i].begin(),R[i].end());
        }
        for(int i=1; i<m; i++)
        {
            int c = m-i;
            for(int j=0; j<L[i].size()-1; j++)
            {
                 int s = L[i][j];
                 int tar = (tot-2*s)/2;
                 //cout<<s<<"  "<<tar<<endl;
                 auto it = lower_bound(R[c].begin(), R[c].end(), tar);
                // cout<<j<<endl;
                 if(it!=R[c].end())
                 {
                 int p=*it;
                // cout<<p<<endl;
                 res=min(res, abs(tot-2*(p+s)));

                 }
                 if(it!=R[c].begin())
                 {
                 it--;
                 int p=*it;
               //  cout<<p<<endl;
                 res=min(res, abs(tot-2*(p+s)));
                 }
                 //cout<<res<<endl;

            }
        }
        return res;
    }
};

/*
0  0
1  7
1  9
2  16
0  0
1  3
1  3
2  6
*/