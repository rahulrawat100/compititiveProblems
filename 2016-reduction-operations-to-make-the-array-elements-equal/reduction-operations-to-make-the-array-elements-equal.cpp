class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> D;
        int n= nums.size();

        for(int i=0; i<n; i++)
        {
            D[nums[i]]++;
        }

        auto it=D.end();
        it--;
        int res=0;
        while(it!=D.begin())
        {
           res+=it->second;
           int curr=it->second;
           it--;
           it->second+=curr;
        }
        return res;
    }
};