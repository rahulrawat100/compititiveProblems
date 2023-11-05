class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int count=0;
        int res=arr[0];
        for(int i=1; i<n; i++)
        {
            if(res>arr[i])
            {
                count++;
                if(count==k)return res;
            }
            else
            {
                count=1;
                res=arr[i];
                if(count==k)return res;
            }
        }
        return res;


    }
};