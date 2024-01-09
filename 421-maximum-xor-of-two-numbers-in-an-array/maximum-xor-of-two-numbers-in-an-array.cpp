class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        int res=0;
        unordered_set<int> D;
        for(int i=30; i>=0; i--)
        {
           res+=pow(2, i);

           for(int i=0; i<n; i++)
           {
              D.insert(nums[i]&res);
           }
           bool poss=false;
           for(auto it: D)
           {
               if(D.find(res^it)!=D.end())
               {
                   poss=true;
                   break;
               }
           }
           if(!poss)
           {
               res-=pow(2, i);
           }
           D.clear();
        }
        return res;
    }
};

// X

// X=16


// A^B=X
// X^(A^B)=X^X

// X^A^B=0



