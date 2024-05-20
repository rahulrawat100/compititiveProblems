class Solution {
public:
    vector<pair<int, int>> Sorty(vector<pair<int, int>>& D, int i, int j, vector<int>&DP, int diff)
    {
        //cout<<i<<" "<<j<<endl;
        if(i>j)
           return {{}};
        if(i==j)
           return {D[i]};
        else
        {
            int mid = i+(j-i)/2;
            vector<pair<int, int>> left = Sorty(D, i, mid, DP, diff);
            vector<pair<int, int>> right = Sorty(D, mid+1, j, DP, diff);
             return merge(left, right, DP, diff);
            //return left;
        }   
    }


    vector<pair<int, int>> merge(vector<pair<int, int>>& left, vector<pair<int, int>>& right, vector<int>& DP, int diff)
    {
        vector<pair<int, int>> res;
        int m = left.size();
        int n = right.size();
        int i=0; 
        int j=0;
        for(;j<n;j++)
        {
            for(;i<m;i++)
            {
                if(left[i].first>right[j].first+diff)
                   break;
            }
            //cout<<right[j].second<<"  "<<i<<endl;
            DP[right[j].second]+=i;
        }
        i=0;
        j=0;
        while(i<m||j<n)
        {
            if(i<m&&j<n)
            {
                if(left[i].first<=right[j].first)
                   {
                      res.push_back(left[i]);
                      i++;
                   }
                   else
                   {
                      res.push_back(right[j]);
                      j++;
                   }
            }
            else if(i<m)
            {
                    res.push_back(left[i]);
                      i++;
            }
            else
            {
                res.push_back(right[j]);
                      j++;
            }
        }
        return res;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        vector<pair<int, int>> D;
        for(int i=0; i<n; i++)
        {
            D.push_back({nums1[i]-nums2[i], i});
        }
        vector<int>DP(n, 0);
      D= Sorty(D, 0, n-1, DP, diff);
        long long res=0;
       for(int i=0; i<n; i++)
        {
            //cout<<C[i].first<<"  "<<C[i].second<<"  "<<DP[i]<<endl;
            res+=DP[i];
        }
        return res;

    }
};

//1 0 4
//

//      1              0               4
//      