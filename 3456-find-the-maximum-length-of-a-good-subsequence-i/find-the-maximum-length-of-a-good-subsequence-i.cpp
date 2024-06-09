class Solution {
public:
    int calc(vector<int>& nums,int i, int k, int prev, vector<vector<vector<int>>>& DP)
    {
                //cout<<k<<"-k  i-"<<i<<"   "<<endl;
        if(i==nums.size())
            return 0;
       if(DP[i][prev][k]!=-1)
            return DP[i][prev][k];
        else
        {
            if(prev==nums.size())
               DP[i][prev][k]=max(calc(nums, i+1, k, prev, DP),1+calc(nums, i+1, k, nums[i], DP));
            else if(nums[i]==prev)
                DP[i][prev][k]=1+calc(nums, i+1, k, nums[i], DP);
            else if(k==0)
                DP[i][prev][k]=calc(nums, i+1, k, prev, DP);
            else
                DP[i][prev][k]=max(1+calc(nums, i+1, k-1, nums[i], DP), calc(nums, i+1, k, prev, DP));
               //         cout<<"k-"<<k<<"  i-"<<i<<"   prev-"<<prev<<"   ";
                //cout<<DP[i][prev][k]<<endl; 
                return DP[i][prev][k]; 
        }
    }
    int maximumLength(vector<int>& nums, int k) {
        int n =nums.size();
         set<int> S;
         for(int i=0; i<n; i++)
         {
            S.insert(nums[i]);
         }
         unordered_map<int, int> D;
         int c=0;
         for(auto it: S)
         {
            D[it]=c++;
         }
         for(int i=0; i<n; i++)
         {
            nums[i]=D[nums[i]];
           // cout<<nums[i]<<endl;
         }

        vector<vector<vector<int>>> DP(n, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return calc(nums, 0, k, n, DP);
    }
};