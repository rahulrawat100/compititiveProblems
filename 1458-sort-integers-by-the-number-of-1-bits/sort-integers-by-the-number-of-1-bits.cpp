class Solution {
public:
   static int bitter(int a)
   {
       int c=0;
       while(a>0)
       {
          if(a%2==1)
             c++;
           a=a/2;  
       }
       return c;
   }
    static bool comp(int a, int b)
    {
         int c1 = bitter(a);
         int c2 = bitter(b);

         if(c1<c2)return true;
         if(c1==c2)return a<b;
         return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
       
    }
};