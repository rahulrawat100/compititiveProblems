class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        	int len = nums.size();
	
	priority_queue<int> pq;
	for(int i=0; i<len; i++)
	{
		pq.push(nums[i]);
	}
	long long res=0;

	while(k>0)
	{
		res+=pq.top();
		int x = pq.top();
		pq.pop();
		pq.push(ceil(x/3.0));
        k--;
	}
	
	return res;

    }
};