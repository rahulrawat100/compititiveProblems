class Solution {
public:
    int build(vector<int>& nums,vector<int>& ST, int i, int j, int ind)
    {
        if(j==i)
            return ST[ind]=0;
        else
        {
            int mid = i+(j-i)/2;
            int X = build(nums,ST, i, mid, 2*ind+1);
            int Y = build(nums,ST, mid+1, j, 2*ind+2);
            int c=0;
            if(mid-1>=i&&mid+1<=j&&nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid])
                c++;
            if(mid>=i&&mid+2<=j&&nums[mid]<nums[mid+1]&&nums[mid+2]<nums[mid+1])
                c++;     
            return ST[ind]=c+X+Y;
        }
    }
    
    int update(vector<int>& nums,vector<int>& ST, int i, int j, int ind, int x)
    {
        if(x<i||x>j)
            return ST[ind];
       // cout<<i<<"  "<<j<<endl;    
        if(j==i)
            return ST[ind];
        else
        {
            int mid = i+(j-i)/2;
            int X = update(nums,ST, i, mid, 2*ind+1, x);
            int Y = update(nums,ST, mid+1, j, 2*ind+2, x);
            int c=0;
            if(mid-1>=i&&mid+1<=j&&nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid])
                 c++;
            if(mid>=i&&mid+2<=j&&nums[mid]<nums[mid+1]&&nums[mid+2]<nums[mid+1])
                c++;       
            return ST[ind]=c+X+Y;
        }
    }
    
    int GetVal(vector<int>& nums,vector<int>& ST, int i, int j, int l, int r, int ind)
    {
        if(r<i||l>j)
            return 0;
               
        if(i>=l&&j<=r)
            return ST[ind];
        else
        {
            int mid = i+(j-i)/2;
            int c=0;
            
            if(mid-1>=max(i, l)&&mid+1<=min(r,j)&&nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid])
            {
                //cout<<nums[mid-1]<<"   "<<nums[mid]<<"   "<<nums[mid+1]<<endl;
               // cout<<nums[mid]<<"   "<<nums[mid+1]<<"   "<<nums[mid+2]<<endl;
                c++;
            }
            if(mid>=max(i, l)&&mid+2<=min(r, j)&&nums[mid]<nums[mid+1]&&nums[mid+2]<nums[mid+1])
            {
                // cout<<nums[mid]<<"   "<<nums[mid+1]<<"   "<<nums[mid+2]<<endl;
                c++;
            }
              int res;    
            res=c+GetVal(nums,ST,  i, mid,l, r, 2*ind+1) + GetVal(nums,ST, mid+1, j, l, r, 2*ind+2);
           // cout<<i<<" - "<<j<<"   "; 
            //cout<<res<<endl;
            return res;
        }
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<int> res;
        int n =nums.size();
        vector<int> ST(4*n);
        build(nums, ST, 0, n-1, 0);
        for(int i=0; i<m; i++)
        {
            int t = queries[i][0];
            if(t==1)
            {
                int l = queries[i][1];
                int r = queries[i][2];
                res.push_back(GetVal(nums, ST, 0, n-1, l, r, 0));
            }
            else
            {
                int ind = queries[i][1];
                int val = queries[i][2];
                nums[ind]=val;
                update(nums, ST, 0, n-1, 0, ind);
                // for(int j=0; j<ST.size(); j++)
                // {
                //     cout<<ST[j]<<"   ";
                // }
                // cout<<endl;
                
            }

        }
        return res;
        
    }
};