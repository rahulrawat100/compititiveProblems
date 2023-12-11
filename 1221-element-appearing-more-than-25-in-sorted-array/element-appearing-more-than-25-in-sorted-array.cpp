class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int num=arr[0];
        int count=1;
        int n = arr.size();
        for(int i=1; i<n; i++)
        {
              if(arr[i]==num)
                 count++;
              else
              {
                  num=arr[i];
                  count=1;
              }   
              if(count>n/4)
                return num;
        }
        return num;
    }
};