class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();

        int s = ceil(sqrt(n));

        vector<vector<pair<int, int>>> D;
        vector<int> val;
        cout<<s<<endl;
        for(int i=0; i<n; i+=s)
        {
            vector<pair<int, int>> E;
            int t = INT_MIN;
            for(int j=0; j<s&&j+i<n; j++)
            {
                E.push_back({i+j, baskets[i+j]});
                t = max(t, baskets[i+j]);
            }
            D.push_back(E);
            val.push_back(t);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int j=0;
            for(j=0; j<val.size(); j++)
            {
                 //cout<<val[j]<<"  "<<fruits[i]<<endl;
                if(val[j]>=fruits[i])
                {
                    int t= 0;
                    for(int k=0; k<D[j].size(); k++)
                    {
                        if(fruits[i]<=D[j][k].second)
                        {
                            D[j][k].second=0;
                            break;
                        }
                    }
                    for(int k=0; k<D[j].size(); k++)
                    {
                        t = max(t, D[j][k].second);
                    }
                //    cout<<t<<endl;
                    val[j]=t;
                    break;
                }
            }
            if(j==val.size())
              ans++;
        }
        return ans;
    }
};