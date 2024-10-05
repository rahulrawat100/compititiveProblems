class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
           int len = nums.size();

   vector<pair<int, int>> pairs;

   for(int i=0; i<len; i++)
   {
      pairs.push_back({nums[i], i});
   }

   sort(pairs.begin(), pairs.end());
   
   vector<int> ranks(len);
   int curr=1;
   for(int i=0; i<len; i++)
   {
      if(i>0&&pairs[i].first!=pairs[i-1].first)
         curr++;
      ranks[pairs[i].second]=curr;
   }
   return ranks;
    }
};