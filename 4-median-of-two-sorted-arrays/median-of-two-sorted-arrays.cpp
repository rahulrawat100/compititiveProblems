class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
         if(n>m)
           return findMedianSortedArrays(nums2, nums1);
        int ele= (n+m+1)/2;
         int s=0;
         int e=n;
         double l1, r1, l2, r2;
         while(s<=e)
         {
             int mid = s+(e-s)/2;
             int mid2 = ele-mid;
             cout<<mid<<"  "<<mid2<<endl;
             l1= mid==0?INT_MIN:nums1[mid-1];
             r1=mid==n?INT_MAX:nums1[mid];
             l2=mid2==0?INT_MIN:nums2[mid2-1];
             r2=mid2==m?INT_MAX:nums2[mid2];

             if(l1<=r2&&l2<=r1)
               return (m+n)%2==0? (max(l1, l2)+min(r1, r2))/2:max(l1, l2);
             else if(r1<l2)
               s=mid+1;
             else
               e=mid-1;  
         }
         return 0;

    }
};