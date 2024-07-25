class Solution {
public:
    vector<int> sort(vector<int>& nums, int i, int j)
    {
        if(i==j)
           return {nums[i]};
        else
        {
            int mid = i+(j-i)/2;
            vector<int> L = sort(nums, i, mid);
            vector<int> R = sort(nums, mid+1, j);
            merge(L, R);
            return L;
        }   
    }

    void merge(vector<int>& L, vector<int>& R)
    {
        vector<int> res;
        int m =L.size();
        int n = R.size();

        int i=0; 
        int j=0;

        while(i<m || j<n)
        {
            if(i<m&&j<n)
            {
                if(L[i]<R[j])
                {
                    res.push_back(L[i]);
                    i++;
                }
                else
                {
                    res.push_back(R[j]);
                    j++;
                }
            }
            else if(i<m)
            {
                   res.push_back(L[i]);
                    i++; 
            }
            else
            {
                    res.push_back(R[j]);
                    j++;
            }
        }
        L=res;
    }
    vector<int> sortArray(vector<int>& nums) {
        return sort(nums, 0, nums.size()-1);
    }
};