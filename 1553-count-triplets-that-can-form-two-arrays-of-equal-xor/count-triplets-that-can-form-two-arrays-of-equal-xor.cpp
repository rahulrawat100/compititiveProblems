class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int, pair<int, int>> D;
        int x=0;
        D[0]={0,1};
        int res=0;
        for(int i=0; i<n; i++)
        {
           x=x^arr[i];
           //cout<<x<<endl;
           if(D.find(x)!=D.end())
           {
                  res+=i*D[x].second-D[x].first;
                  D[x]={D[x].first+i+1, D[x].second+1};
           }
           else
               D[x]={i+1, 1};
           
        }
        return res;
    }
};