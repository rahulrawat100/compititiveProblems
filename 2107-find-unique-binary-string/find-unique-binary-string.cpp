class Solution {
public:
    string calc(int x, unordered_set<string>& D, string t)
    {
        if(x==0)
          {
              if(D.find(t)==D.end())
                 return t;
              return "";   
          }
        else
          {
              string s;
              s= calc(x-1, D, t+"0");
              if(s.size()>0)
                 return s;
              return calc(x-1, D, t+"1");
          }
            
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<string> D;
        
        for(int i=0; i<nums.size(); i++)
        {
            D.insert(nums[i]);
        }
      return calc(nums.size(), D, "");
        
    }
};