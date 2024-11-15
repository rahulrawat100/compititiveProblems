class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i;
        for(i=n-2; i>=0; i--)
        {
            if(arr[i]>arr[i+1])
                break;
        }
        i++;
        if(i==0)return 0;

        int res=i;
        for(int j=0; j<n; j++)
        {
            if(j>0&&arr[j]<arr[j-1])
                break;
            while(i<n&&arr[i]<arr[j])
            {
                i++;
            }
            res=min(res, i-j-1);
        }
        return res;
    }
};