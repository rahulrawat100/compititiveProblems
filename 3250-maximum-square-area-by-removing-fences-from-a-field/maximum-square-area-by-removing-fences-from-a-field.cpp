class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_map<int, int> D;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.insert(hFences.begin(),1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(),1);
        vFences.push_back(n);
        for(int i=0; i<hFences.size(); i++)
        {
            for(int j=i+1; j<hFences.size(); j++)
            {
                if(D.find(hFences[j]-hFences[i])==D.end())
                     D[hFences[j]-hFences[i]]=1;
            }
        }
        long long ans=-1;
        for(int i=0; i<vFences.size(); i++)
        {
            for(int j=i+1; j<vFences.size(); j++)
            {
                long long s=vFences[j]-vFences[i];
                s=s*s;
                if(D.find(vFences[j]-vFences[i])!=D.end())
                    ans=max(ans, s);
            }
        }
        return ans%1000000007;
        
        
    }
};