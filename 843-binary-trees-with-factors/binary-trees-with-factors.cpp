class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> D;
        long long count=0;
        for(int i=0; i<n; i++)
        {
            D[arr[i]]=1;
            for(int j=i-1;j>=0; j--)
            {
                if(arr[i]%arr[j]==0&&D.find(arr[i]/arr[j])!=D.end())
                {
                   D[arr[i]]+=D[arr[j]]*D[arr[i]/arr[j]];
                   D[arr[i]]%=1000000007;
                }
            }
            count+=D[arr[i]];
            count=count%1000000007;
        }
        return count;
    }
};