class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> D;

        int n = arr.size();

        for(int i=0; i<n; i++)
        {
            int m = arr[i];
            int c=0;
            while(m>0)
            {
                if(m%2==1)c++;
                m=m/2;
            }
            D.push_back({c, arr[i]});
        }
        sort(D.begin(), D.end());
        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i]=D[i].second;
        }
        return res;
    }
};