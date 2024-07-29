class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> D;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(D.find(nums[i])!=D.end())
              return true;
            D.insert(nums[i]);  
        }
        return false;
    }
};