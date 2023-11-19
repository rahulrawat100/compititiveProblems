class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int freq=0;
        for(int i=n-1; i>=0; i--)
        {
            int tno= nums[i];
            int tfreq=1;
            int j=i-1;
            while(j>=0&&nums[j]==tno)
            {
                tfreq++;
                j--;
            }
            i=j+1;
            int tk=k;
            while(tk>0&&j>=0)
            {
                tk=tk-(tno-nums[j]);
                if(tk>=0)
                    tfreq++;
                else
                    break;
                j--;
            }
            if(tfreq>freq)
                freq=tfreq;
        }
        return freq;
    }
};