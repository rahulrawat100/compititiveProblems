class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int m = target.size();
        int c=1;
        for(int i=0; i<m;)
        {
           if(target[i]==c)
           {
               res.push_back("Push");
               i++;
           }
           else
           {
               res.push_back("Push");
               res.push_back("Pop");
           }
           c++;
        }
        return res;
    }
};