class NumArray {
public:
     vector<int> ST;
     int n;
    void create(vector<int>& nums, int i, int j, int ind)
    {
        if(i>j)
          return;
        if(i==j)
        {
            //cout<<ind<<"  "<<nums[i]<<endl;;
            ST[ind]=nums[i];
            return;
        }
        else
        {
            int mid = i+(j-i)/2;
            int left=2*ind+1;
            int right =2*ind+2;
            create(nums,  i, mid, left);
            create(nums,  mid+1, j, right);
            ST[ind]=ST[left]+ST[right];
            return ;
        }
          
    }

    NumArray(vector<int>& nums) {
         n = nums.size();
        ST.resize(4*n);
        create(nums,0, n-1, 0);
       // cout<<"create"<<endl;
    }
    
    void update(int i, int j, int ind, int index, int val)
    {
       // cout<<"update"<<endl;
        if(index<i || index>j)
          return;
        else if(i==j)
          {
              ST[ind]=val;
          }
         else 
         {
            int mid = i+(j-i)/2;
            int left=2*ind+1;
            int right =2*ind+2;
            update(i, mid, left, index, val);
            update(mid+1, j, right, index, val);
            ST[ind]=ST[left]+ST[right];
        }  
       // cout<<"Eupdate"<<endl;

    }
    void update(int index, int val) {
         //cout<<"update"<<endl;
        return update(0, n-1, 0, index, val);
    }
    
     int sum(int i, int j, int left, int right, int ind)
     {
        //cout<<ind<<endl;
         if(i>j)
           return 0;
         if(right<i || left>j)
          return 0;
         else if(left<=i&&right>=j)
           return ST[ind]; 
         else
         {
             int mid = i+(j-i)/2;
            int left1=2*ind+1;
            int right1 =2*ind+2;
            return sum(i, mid, left, right, left1)+sum(mid+1, j, left, right, right1);

         } 
     }
    int sumRange(int left, int right) {
        // cout<<"sum"<<endl;
        return sum(0, n-1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */