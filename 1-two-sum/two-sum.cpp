class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> D;
                
                        for(int i=0; i<nums.size(); i++)
                                {
                                            if(D.find(target-nums[i]) == D.end())
                                                            D[nums[i]]=i;
                                                                        else
                                                                                        return {D[target-nums[i]], i};
                                                                                                }
                                                                                                        return {};
    }
};