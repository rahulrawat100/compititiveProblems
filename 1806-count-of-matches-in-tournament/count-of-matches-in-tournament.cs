public class Solution {
    public int NumberOfMatches(int n) {
        if(n==1)
           return 0;
        if(n==2)
          return 1;
       else
          return n/2+NumberOfMatches((n+1)/2);   
    }
}