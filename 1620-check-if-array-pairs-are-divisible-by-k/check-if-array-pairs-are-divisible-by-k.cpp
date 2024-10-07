class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        long long  sum=0;
        for(int i=0; i<n; i++)
        {
           // cout<<arr[i]<<"  ";
            while(arr[i]<0)
            {
                arr[i]+=k;
            }
            arr[i]%=k;
          //  cout<<arr[i]<<endl;
            sum+=arr[i];
        }

        // if(sum%k!=0)
        //    return false;

       unordered_map<int, int> D;
       int used=0;
       for(int i=0; i<n; i++)
       {
            int tar = arr[i]==0?0:k-arr[i];
            if(D.find(tar)!=D.end()&&D[tar]>0)
            {
                D[tar]--;
                used+=2;
                
            }
            else
            {
                D[arr[i]]++;
            }
       }

       return used==n;    
    }
};