class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int, vector<int>> D;
        int x=0;
        D[0].push_back(0);
        int res=0;
        for(int i=0; i<n; i++)
        {
           x=x^arr[i];
           //cout<<x<<endl;
           if(D.find(x)!=D.end())
           {
              for(int j=0; j<D[x].size();j++)
                  res+=i-D[x][j];
           }
           D[x].push_back(i+1);
        }
        return res;
    }
};