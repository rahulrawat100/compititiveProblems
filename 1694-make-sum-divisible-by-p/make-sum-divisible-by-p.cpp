class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    int extra=0;
   int len =nums.size();
    
   for(int i=0; i<len; i++)
   {
      extra+=nums[i];
      extra%=p;
   }
   if(extra==0)return 0;
   int res=len;

   unordered_map<int, int> lastmodPos;
   lastmodPos[0]=0;
   long long sum=0;
   for(int i=0; i<len; i++)
   {
       sum+=nums[i];
       int tar=(sum-extra)%p;   
       if(tar>=0&&lastmodPos.find(tar)!=lastmodPos.end())
          res=min(res, i+1-lastmodPos[tar]);
       lastmodPos[sum%p]=i+1;  
   }
   return res==len?-1:res;
    }
};