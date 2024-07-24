class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, pair<int,int>>> D;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            int x =0;
            int y=nums[i];
            int p=1;
            if(y==0)
               x=mapping[0];
            while(y>0)
            {
                int dig = y%10;
                dig=mapping[dig];
                x+=dig*p;
                y=y/10;
                p*=10;
            }
            //cout<<x<<endl;
            D.push_back({x, {i,nums[i]}});
        }
        sort(D.begin(), D.end());

        vector<int> res;
        for(int i=0; i<n; i++)
        {
            res.push_back(D[i].second.second);
        }
        return res;
    }
};