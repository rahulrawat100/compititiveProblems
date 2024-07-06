class Solution {
public:
    int passThePillow(int n, int time) {
        int round = time/(n-1);
        int t=time%(n-1);
        if(round%2==0)
          return t+1;
        else
         return   n-t;
    }
};