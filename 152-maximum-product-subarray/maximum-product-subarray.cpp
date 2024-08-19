class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double curr_max = nums[0];
        double curr_min = nums[0];
        int ans = nums[0];
        for(int i = 1 ;i < nums.size() ; i++){
            double temp_max = curr_max;
            curr_max = max((double)nums[i] , max(curr_max*nums[i] , curr_min*nums[i]));
            curr_min = min((double)nums[i] , min(temp_max*nums[i] , curr_min*nums[i]));
            ans = max(ans , (int)curr_max);
        }
        return ans;
    }
};